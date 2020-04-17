#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010
char T[MAXN] = "GATAGACA$";
int SA[MAXN], i, n;
string s = "GATAGACA$";

inline bool cmp(int a, int b) { return s.substr(a).compare(s.substr(b)) < 0; }

// n^2 lg n
int main() {
  int n = s.length();

  //   initial SA {0, 1, 2, ..., n - 1}
  for (int i = 0; i < n; ++i) SA[i] = i;

  sort(SA, SA + n, cmp);
  cout << endl;
  for (int i = 0; i < n; ++i) cout << s.substr(T[i]) << endl;
}