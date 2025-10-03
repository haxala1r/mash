#pragma once
#include <value.hpp>
#include <lex.hpp>




// The Parser produces a regular lisp value.
// lisp code is made of lisp lists and atoms.
class Parser {
private:
    // the token stream.
    std::deque<Token> ts;
    Token get_token();
    void unget_token(Token);

    // these may need to be interned later
    String make_string(std::string);
    Symbol make_symbol(std::string);


    std::optional<LispValue> parse_one();
    LispValue parse_list();

public:
    Parser(Lexer);

    void feed(Lexer);

    std::optional<LispValue> next();
};

