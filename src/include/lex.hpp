#pragma once
#include <deque>
#include <sstream>
#include <vector>
#include <stdint.h>
#include <variant>
#include <optional>

enum TokenType {
    OpenParen,
    CloseParen,
    Dollar,
    Symbol,
    String,
    Int,
    Double,
    End
};

// Plain Old Data
struct Token {
    enum TokenType type;
    std::optional<std::variant<int64_t, double, std::string>> value;
};
bool operator==(Token const& one, Token const& other);
std::ostream &operator<<(std::ostream &os, Token const &t);

class Lexer {
private:
    // we use a stringstream for lexing purposes
    std::stringstream ss;

    Token lexNumOrSym();
    Token lexString();
    Token lexNonSpecial();

public:
    Lexer(std::string);
    Lexer();

    void feed(std::string);
    
    Token next();
    std::deque<Token> collect();
};

// when you don't want to construct the object
std::deque<Token> lex(std::string);
