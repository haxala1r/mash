#pragma once
#include <sstream>
#include <vector>
#include <stdint.h>
#include <variant>

enum TokenType {
    OpenParen,
    CloseParen,
    Dollar,
    Symbol,
    String,
    Int,
    End
};

// Plain Old Data
struct Token {
    enum TokenType type;
    std::variant<int64_t, std::string> value;
};
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
    std::vector<Token> collect();
};

// when you don't want to construct the object
std::vector<Token> lex(std::string);
