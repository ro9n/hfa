/**
 * @file 007.059A - Word.cpp
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

    int l = 0, u = 0;

    for(char c: s) {
        if(c < 'a') ++u;
        else ++l;
    }

    if (u > l) {
        for(int i = 0; i < s.size(); ++i) {
            s[i] = toupper(s[i]);
        }
    } else {
       for(int i = 0; i < s.size(); ++i) {
            s[i] = tolower(s[i]);
        } 
    }

    cout << s << endl;
    return 0;
}