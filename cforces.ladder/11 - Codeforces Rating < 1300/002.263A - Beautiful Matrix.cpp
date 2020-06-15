#include <bits/stdc++.h>

using namespace std;

int main() {
  int k, x, y;

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> k;
      if (k) {
        x = i, y = j;
      }
    }
  }

  // manhatten distance
  cout << abs(x - 2) + abs(y - 2);
  return 0;
}