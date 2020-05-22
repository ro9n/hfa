#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        
        int l = 0;
        int r = n - 1;
        
        bool f = 0;
        
        while(l < r) {
            while (l < r && s[l] == s[r]) {
                ++l;
                --r;
            }
            
            if(l >= r) return 1;
            
            if (f) return 0;
            
            if (l + 1 == r) return 0;
            else if (l + 1 < n && s[l + 1] == s[r]) ++l, f = 1;
            else if (r - 1 >= 0 && s[l] == s[r - 1]) --r, f = 1;
            else return 0;
        }
        
        return 1;
    }
};

int main() {
    auto s = new Solution();
    if(s->validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga")) {
        cout << "y" << endl;
    }

    return 0;
}