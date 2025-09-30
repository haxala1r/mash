#include <cstdlib>
#include <exception>
#include <iostream>
#include <lex.hpp>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

bool ispunct(char c) {
    for (char i : "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~") {
        if (i == c) return true;
    }
    return false;
}

bool isSymbolChar(char c) {
    return c != '(' && c != ')' && isgraph(c);
}

Lexer::Lexer(string s) : ss(s) {}
Lexer::Lexer() : ss("") {}

void Lexer::feed(string s) {
    ss << s;
}

Token Lexer::lexNumOrSym() {
    // first we take the part that is either a number or symbol, then
    // we'll determine which it is.
    stringstream acc("");
    while (true) {
        char c = ss.get();
        if (ss.eof())
            break;
        if (!isSymbolChar(c)) {
            ss.unget();
            break;
        }

        acc << c;
    }

    // TODO:  bigint. also reader base.
    // ... this will almost certainly change, won't it?
    string s = acc.str();
    string iterate_over = (s.at(0) == '-') ? s.substr(1) : s;
    bool is_number = true;
    bool dot_seen = false;
    for (char c : s) {
        if (c == '.') {
            if (dot_seen) {
                is_number = false;
                break;
            }
            dot_seen = true;
        }
        if (!isdigit(c)) {
            is_number = false;
            break;
        }
    }

    if (is_number) {
        return {TokenType::Int, atoll(s.c_str())};
    }
    return {TokenType::Symbol, s};
}

Token Lexer::lexString() {
    ss.get(); // skip the quote.
    stringstream acc("");
    while (true) {
        char c = ss.get();
        if (ss.eof()) {
            cerr << "EOF while reading string.";
            throw exception();
        }
        if (c == '"')
            break;
        acc << c;
    }
    return {TokenType::String, acc.str()};
}

Token Lexer::lexNonSpecial() {
    // This function will not be called unless a character was received.
    char first = ss.peek();
    if (first == '"')
        return lexString();
    else if (isSymbolChar(first))
        return lexNumOrSym();
    else {
        cerr << "Non-printable character found." << endl;
        throw std::exception();
    }
}

Token Lexer::next() {
    while (true) {
        // we MUST check for eof AFTER trying to get a character.
        // ss.eof() doesn't return true until we try to get another
        // character while at EOF, even if we have exhausted the stream.
        char c = ss.get();
        if (ss.eof())
            return {TokenType::End};

        if (isspace(c))
            continue;
        switch (c) {
        case '(': return {TokenType::OpenParen};
        case ')': return {TokenType::CloseParen};
        case '$': return {TokenType::Dollar};
        default:
            ss.unget();
            return lexNonSpecial();
        }
    }
}



