/**
 * @file 020.339A - Helpful Maths.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wed Jun 17 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin , s);

    int c1 = 0, c2 = 0, c3 = 0, j = 0;
    for (int i = 0; i < s.size(); i += 2) {
        if (s[i] == '1') ++c1;
        else if (s[i] == '2') ++c2;
        else ++c3;
    }

    while (c1--) s[j] = '1', j += 2;
    while (c2--) s[j] = '2', j += 2;
    while (c3--) s[j] = '3', j += 2;

    cout << s << endl;
    return 0;
}