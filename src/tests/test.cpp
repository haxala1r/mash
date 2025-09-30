#include <catch2/catch_test_macros.hpp>
#include <lex.hpp>
using namespace std;

TEST_CASE("Lexer lexes doubles correctly", "[Lexer]") {
    
    SECTION("double and negative syntax") {
        Lexer l("(1.0 0.1 -.1 -1. . - -. .-)");
        REQUIRE(l.next() == Token({OpenParen}));
        REQUIRE(l.next() == Token({Double, 1.0}));
        REQUIRE(l.next() == Token({Double, 0.1}));
        REQUIRE(l.next() == Token({Double, -0.1}));
        REQUIRE(l.next() == Token({Double, -1.0}));
        REQUIRE(l.next() == Token({Symbol, "."}));
        REQUIRE(l.next() == Token({Symbol, "-"}));
        REQUIRE(l.next() == Token({Symbol, "-."}));
        REQUIRE(l.next() == Token({Symbol, ".-"}));
        REQUIRE(l.next() == Token({CloseParen}));
    }
}

