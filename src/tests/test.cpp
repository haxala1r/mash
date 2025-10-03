#include "value.hpp"
#include <catch2/catch_test_macros.hpp>
#include <lex.hpp>
#include <parse.hpp>
using namespace std;

template <typename T>
T pop_and_front(deque<T> &dq) {
    T t = dq.front();
    dq.pop_front();
    return t;
}

TEST_CASE("Lexer lexes doubles correctly", "[Lexer]") {
    
    SECTION("double and negative syntax") {
        Lexer l("(1.0 0.1 -.1 -1. . - -. .-)");
        REQUIRE(l.next() == Token({TokenType::OpenParen, nullopt}));
        REQUIRE(l.next() == Token({TokenType::Double, 1.0}));
        REQUIRE(l.next() == Token({TokenType::Double, 0.1}));
        REQUIRE(l.next() == Token({TokenType::Double, -0.1}));
        REQUIRE(l.next() == Token({TokenType::Double, -1.0}));
        REQUIRE(l.next() == Token({TokenType::Symbol, "."}));
        REQUIRE(l.next() == Token({TokenType::Symbol, "-"}));
        REQUIRE(l.next() == Token({TokenType::Symbol, "-."}));
        REQUIRE(l.next() == Token({TokenType::Symbol, ".-"}));
        REQUIRE(l.next() == Token({TokenType::CloseParen, nullopt}));
    }
}

TEST_CASE("Parser parses correctly", "[Parser]") {
    SECTION("hello world") {
        Parser p (Lexer("(print \"hello world\")"));
        auto dq = get<List>(*p.next()).list;
        REQUIRE(get<Symbol>(pop_and_front(dq)).value == "print");
        REQUIRE(get<String>(pop_and_front(dq)).value == "hello world");
    }
    SECTION("doubles") {
        Parser p (Lexer("(1.0 0.1 -.1 -1. . - -. .-)"));
        auto dq = get<List>(*p.next()).list;
        REQUIRE(get<Double>(pop_and_front(dq)).value == 1.0);
        REQUIRE(get<Double>(pop_and_front(dq)).value == 0.1);
        REQUIRE(get<Double>(pop_and_front(dq)).value == -0.1);
        REQUIRE(get<Double>(pop_and_front(dq)).value == -1.0);
        REQUIRE(get<Symbol>(pop_and_front(dq)).value == ".");
        REQUIRE(get<Symbol>(pop_and_front(dq)).value == "-");
        REQUIRE(get<Symbol>(pop_and_front(dq)).value == "-.");
        REQUIRE(get<Symbol>(pop_and_front(dq)).value == ".-");
    }
    SECTION("Nested lists") {
        Parser p(Lexer("((((0) (1) (2) (3))))"));
        auto l0 = get<List>(*p.next()).list;
        auto l1 = get<List>(pop_and_front(l0)).list;
        auto l2 = get<List>(pop_and_front(l1)).list;

        auto l20 = get<List>(pop_and_front(l2)).list;
        auto l21 = get<List>(pop_and_front(l2)).list;
        auto l22 = get<List>(pop_and_front(l2)).list;
        auto l23 = get<List>(pop_and_front(l2)).list;

        REQUIRE(get<Integer>(pop_and_front(l20)).value == 0);
        REQUIRE(get<Integer>(pop_and_front(l21)).value == 1);
        REQUIRE(get<Integer>(pop_and_front(l22)).value == 2);
        REQUIRE(get<Integer>(pop_and_front(l23)).value == 3);
    }
}

