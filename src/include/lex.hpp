#pragma once
#include <sstream>
#include <vector>
#include <stdint.h>
#include <variant>

enum TokenType {
    OpenParen,
    CloseParen,
    Symbol,
    String,
    Int,
    End
};

// Plain Old Data
struct Token {
    enum TokenType type;
    std::variant<int, std::string> value;
};

class Lexer {
private:
    // we use a stringstream for lexing purposes
    std::stringstream ss;

public:
    Lexer(std::string);
    Lexer();

    void feed(std::string);
    
    Token next();
    std::vector<Token> collect();
};

