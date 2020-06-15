/**
 * @file 005.271A - Beautiful Year.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun Jun 14 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

bool d(int y) {
  set<int> s;
  for (int i = 0; i < 4; ++i) {
    int x = y % 10;
    if (s.count(x)) return 0;

    s.insert(x);
    y /= 10;
  }
  return 1;
}

int main() {
  int y;
  cin >> y;

  for (int x = y + 1;; ++x) {
    if (d(x)) {
      cout << x << endl;
      return 0;
    }
  }

  return 0;
}