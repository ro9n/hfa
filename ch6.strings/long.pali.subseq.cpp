#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

int longestPalindromeSubseq(string s) {
    int n = s.size();
    memo.assign(n, vector<int>(n, 0));
    return lps(s, 0, n - 1);
}

int lps(const string& s, int l, int r) {
    if (l == r)
        return 1;
    else if (l + 1 == r && s[l] == s[r])
        return 2;
    else if (l + 1 == r && s[l] != s[r])
        return 1;
    else if (memo[l][r])
        return memo[l][r];
    else {
        if (s[l] == s[r])
            memo[l][r] = 2 + lps(s, l + 1, r - 1);
        else
            memo[l][r] = max(lps(s, l, r - 1), lps(s, l + 1, r));

        return memo[l][r];
    }
}
