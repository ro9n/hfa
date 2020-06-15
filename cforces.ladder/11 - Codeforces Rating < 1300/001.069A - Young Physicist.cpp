#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int k, c[3];

  memset(c, 0, sizeof(c));

  while (n--) {
    for (int i = 0; i < 3; ++i) {
      cin >> k;
      c[i] += k;
    }
  }

  for (int i = 0; i < 3; ++i) {
    if (c[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}