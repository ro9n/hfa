/**
 * @file 024.141A - Amusing Joke.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu Jun 18 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  string g, h, d;  // guest, host, disordered

  getline(cin, g);
  getline(cin, h);
  getline(cin, d);

  multiset<int> s;

  for (auto c : g) s.insert(c - 'A');
  for (auto c : h) s.insert(c - 'A');
  for (auto c : d) {
    auto it = s.find(c - 'A');
    if (it == s.end()) {
      cout << "NO" << endl;
      return 0;
    }
    s.erase(it);
  }

  if (s.size()) {
    cout << "NO" << endl;
    return 0;
  } else {
    cout << "YES" << endl;
    return 0;
  }
}