#include <iostream>
#include <lex.hpp>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    cout << s << endl;
    
    for (auto t : lex(s)) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}