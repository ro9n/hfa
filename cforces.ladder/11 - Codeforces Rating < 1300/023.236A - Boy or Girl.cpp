/**
 * @file 023.236A - Boy or Girl.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu Jun 18 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s;
    string w; cin >> w;
    for(auto c: w) s.insert(c);
    if(s.size() & 1) cout << "IGNORE HIM!" << endl;
    else cout << "CHAT WITH HER!" << endl;
    return 0;
}