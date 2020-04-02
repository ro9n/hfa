//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> kmp(const string& t, const string& p) {
    int n = t.size(), m = p.size(), b[m + 1];  // back table
    vector<int> r;                         // result table

    // O(|p|) preprocess the pattern string P
    int i = 0, j = -1;
    b[0] = -1;

    while (i < m) {
        if (j >= 0 && p[i] != p[j]) j = b[j];  // if different, reset j using b
        ++i, ++j;                                 // if same, adv both pointers
        b[i] = j;
    }

    // O(|t|) search
    i = 0, j = 0;
    // search through t
    while (i < n) {
        if (j >= 0 && t[i] != p[j]) j = b[j];  // if different, reset j using b
        ++i, ++j;                                 // if same, adv both pointers
        if (j == m) {
            r.emplace_back(i - j);
            j = b[j];  // prepare j for the next possible match}
        }
    }

    return r;
}

int main() {
    string t = "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN", p = "SEVENTY SEVEN";

    for (int i : kmp(t, p)) {
        cout << i << endl;
    }
}