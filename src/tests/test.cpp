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
}

