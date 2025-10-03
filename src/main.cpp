#include "value.hpp"
#include <iostream>
#include <lex.hpp>
#include <parse.hpp>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    cout << s << endl;
    Parser p(s);
    print_val(*p.next());

    cout << endl;
    return 0;
}