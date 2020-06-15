/**
 * @file 011.080A  - Panoramix's Prediction.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon Jun 15 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

bool p(int k) {
  for (int i = 2; i < (k >> 1) + 1; ++i) {
    if (!(k % i)) {
      // not prime
      return 0;
    }
  }
  return 1;
}

int main() {
  int n, m;
  cin >> n >> m;

  if(!p(m)) {
    cout << "NO" << endl;
    return 0;
  }
  
  for (int j = n + 1; j < m; ++j) {
    if(p(j)) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}