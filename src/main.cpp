#include <iostream>
#include <lex.hpp>
#include <sstream>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    Lexer l(s);
    cout << l.next() << endl;
    return 0;
}