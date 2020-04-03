#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";
    int N = s.size(), best = 0, start = 0;
    vector<vector<bool>> memo(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) memo[i][i] = true;

    for (int l = 1; l < N; ++l) {
        for (int i = 0; i < N - l; ++i) {
            int j = i + l;
            if (i + 1 == j)
                memo[i][j] = s[i] == s[j];
            else {
                memo[i][j] = s[i] == s[j] && memo[i + 1][j - 1];
            }

            if (memo[i][j] && l > best) {
                best = l;
                start = i;
            }
        }
    }

    return s.substr(start, best + 1);
}

int main() {
    cout << longestPalindrome("cbbd") << endl;
}