#include <exception>
#include <iostream>
#include <lex.hpp>
#include <string>
#include <cctype>

using namespace std;

std::ostream &operator<<(std::ostream &os, Token const &t) { 
    os << "Token(";
    switch (t.type) {
    case OpenParen: os << "OpenParen)"; break;
    case CloseParen: os << "CloseParen)"; break;
    case Dollar: os << "Dollar)"; break;
    case Symbol: os << "Symbol, " << get<string>(*t.value) << ")"; break;
    case String: os << "String, \"" << get<string>(*t.value) << "\")"; break;
    case Int: os << "Int, " << get<int64_t>(*t.value) << ")"; break;
    case Double: os << "Double, " << get<double>(*t.value) << ")"; break;
    case End: os << "END)"; break;
    default:
        os << ")";
    }
    return os;
}

bool operator==(Token const& one, Token const& other) {
    return one.type == other.type && one.value == other.value; 
}

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
    bool is_number = false;
    bool dot_seen = false;
    for (char c : iterate_over) {
        
        if (c == '.') {
            if (dot_seen) {
                is_number = false;
                break;
            }
            dot_seen = true;
            continue;
        }
        if (isdigit(c)) {
            is_number = true;
        } else {
            is_number = false;
            break;
        }
    }

    if (is_number && dot_seen) {
        if (iterate_over == ".")
            return {TokenType::Symbol, s};
        return {TokenType::Double, stod(s)};
    } else if (is_number) {
        return {TokenType::Int, stoll(s)};
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
            return {TokenType::End, nullopt};

        if (isspace(c))
            continue;
        switch (c) {
        case '(': return {TokenType::OpenParen, nullopt};
        case ')': return {TokenType::CloseParen, nullopt};
        case '$': return {TokenType::Dollar, nullopt};
        default:
            ss.unget();
            return lexNonSpecial();
        }
    }
}

deque<Token> Lexer::collect() {
    deque<Token> v;
    while (true) {
        Token t = next();
        if (t.type == TokenType::End)
            break;

        v.push_back(t);
    }
    return v;
}

std::deque<Token> lex(std::string s) {
    Lexer l(s);
    return l.collect();
}
