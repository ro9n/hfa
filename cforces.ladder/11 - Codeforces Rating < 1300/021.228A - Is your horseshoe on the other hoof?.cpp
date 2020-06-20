/**
 * @file 021.228A - Is your horseshoe on the other hoof?.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wed Jun 17 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int k; set<int> s;
    cin >> k, s.insert(k);
    cin >> k, s.insert(k);
    cin >> k, s.insert(k);
    cin >> k, s.insert(k);

    cout << 4 - s.size() << endl;
    return 0;
}