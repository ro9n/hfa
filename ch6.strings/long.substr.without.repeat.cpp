#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int l = 0, r = 1, best = 1, n = s.size();

        unordered_set<char> ss;
        ss.insert(s[0]);

        while (l < n && r < n) {
            if (ss.find(s[r]) == ss.end()) {
                ss.insert(s[r]);
                best = max(best, r - l + 1);
                ++r;
            } else {
                ss.erase(s[l++]);
            }
        }

        return best;
    }
};