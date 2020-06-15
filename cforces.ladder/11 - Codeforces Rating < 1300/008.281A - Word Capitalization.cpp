/**
 * @file 008.281A - Word Capitalization.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon Jun 15 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    if (s[0] > 'Z') s[0] -= 32;
    cout << s << endl;
    return 0;
}