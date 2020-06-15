#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  getline(cin, s);

  int n = s.size(), j = 0;
  char d[n];

  for (int i = 0; i < n; ++i) {
    if (i + 1 < n && s[i] == '-') {
      ++i;
      if (s[i] == '.')
        d[j++] = '1';
      else
        d[j++] = '2';
    } else
      d[j++] = '0';
  }

  for (int i = 0; i < j; ++i) cout << d[i];
  cout << endl;

  return 0;
}