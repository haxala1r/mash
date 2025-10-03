#include <exception>
#include <lex.hpp>

#include <parse.hpp>

#include <iostream>

using namespace std;

Parser::Parser(Lexer l) : ts(l.collect()) {}

void Parser::feed(Lexer l) {
    ts.append_range(l.collect());
}

Token Parser::get_token() {
    if (ts.empty()) {
        cerr << "Parser::get_token: Token requested at input end." << endl;
        throw exception();
    }
    Token t = ts.front();
    ts.pop_front();
    return t;
}
void Parser::unget_token(Token t) {
    ts.push_front(t);
}

String Parser::make_string(string s) {
    return String {s};
}

Symbol Parser::make_symbol(string s) {
    return Symbol {s};
}

LispValue Parser::parse_quote() {
    // in regular lisps, a quote gets expanded to a (quote) form.
    // i.e. 'a is actually (QUOTE A). This prevents the symbol from being
    // evaluated.
    // This is the same way we'll handle quotes for now, because I can't
    // think of anything else.
    List l;

    l.list.push_back(make_symbol("QUOTE"));
    auto next = parse_one();
    // this is guaranteed to work, because if we do not have enough tokens
    // to constitute another value Parser::get_token will throw an exception
    l.list.push_back(*next);
    return l;
}

optional<LispValue> Parser::parse_one() {
    Token t = get_token();
    switch (t.type) {
    case TokenType::Int: return Integer {get<int64_t>(*t.value)};
    case TokenType::Double: return Double {get<double>(*t.value)};
    case TokenType::String: return make_string(get<string>(*t.value));
    case TokenType::Symbol: return make_symbol(get<string>(*t.value));
    case TokenType::OpenParen: return parse_list();
    case TokenType::CloseParen: throw "whatever";
    case TokenType::Quote: return parse_quote();

    // I don't know what this will actually do, in theory maybe just like the OpenParen,
    // but parses things in a different namespace? unimplemented for now.
    case TokenType::Dollar: return parse_one();
    case TokenType::End : return nullopt;
    }
    return nullopt;
}

LispValue Parser::parse_list() {
    // assumes that we have read the OpenParen, and are reading elements until
    // we find the CloseParen
    List l;
    Token t = get_token();

    while (true) {
        if (t.type == TokenType::End) {
            // this is clearly an error!
            cerr << "Parser::parse_list: Input ended before list ended." << endl;
            break;
        }
        if (t.type == TokenType::CloseParen)
            break;
        unget_token(t);
        l.list.push_back(*parse_one());
        t = get_token();
    }
    return l;
}


optional<LispValue> Parser::next() {
    return parse_one();
}
