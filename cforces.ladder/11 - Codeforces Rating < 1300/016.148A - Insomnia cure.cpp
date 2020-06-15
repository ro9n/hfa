/**
 * @file 016.148A - Insomnia cure.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tue Jun 16 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[4], d;
  for (int i = 0; i < 4; ++i) cin >> a[i];
  cin >> d;

  if (a[0] == 1 || a[1] == 1 || a[2] == 1 || a[3] == 1) {
    cout << d << endl;
  } else {
    set<int> s;
    for (int j = 0; j < 4; ++j) {
      for (int i = 1; i <= d; ++i) {
          if (!(i % a[j])) s.insert(i);
      }
    }

    cout << s.size() << endl;
  }
  return 0;
}