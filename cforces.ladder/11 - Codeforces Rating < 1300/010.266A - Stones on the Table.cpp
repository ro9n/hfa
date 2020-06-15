/**
 * @file 010.266A - Stones on the Table.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon Jun 15 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int l = 0, r = 1, d = 0, n;
    string s;

    cin >> n;
    getchar();
    getline(cin, s);

    while(r < n) {
        while (r < n && s[l] == s[r]) {
            ++d, ++r;
        }

        l = r++;
    }

    cout << d << endl;

    return 0;
}