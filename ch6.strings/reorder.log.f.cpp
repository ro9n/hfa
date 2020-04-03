#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    static int mysort(const string& a, const string& b) {
        int i = a.find(' '), j = b.find(' ');

        // 1 alpha 1 digit
        if (isalpha(a[i + 1]) ^ isalpha(b[j + 1])) return isalpha(a[i + 1]);

        // both digit: sort by id
        else if (isdigit(a[i + 1]))
            return 0;
        // both alpha
        int cmp = a.substr(i + 1).compare(b.substr(j + 1));
        return !cmp ? a.substr(0, i - 1).compare(b.substr(0, j - 1)) < 0 : cmp < 0;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), mysort);
        return logs;
    }
};