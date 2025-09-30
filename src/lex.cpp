#include <lex.hpp>
#include <string>

Lexer::Lexer(std::string s) : ss(s) {}
Lexer::Lexer() : ss("") {}

void Lexer::feed(std::string s) {
    ss << s;
}

Token Lexer::next() {
    return {TokenType::CloseParen};
}



