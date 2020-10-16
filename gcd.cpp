/**
 * @file gcd
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 15 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long

/**
 * Euclidean algorithm
 */
ll gcd_euclidean(int x, int y) {
  // 0 divides everything
  if (!x) return y;
  if (!y) return x;

  // base case
  if (x == y) return x;

  if (x > y) return (x - y, y);
  return gcd_euclidean(x, y - x);
}

// More efficient euclidian using modulo O(lg min(a,b))
ll gcd(int x, int y) {
  if (!y) return x;
  return gcd(y, x % y);
}

ll lcm(int x, int y) {
  // if (!x || !y) return 0;
  // else if (x == 1 || y == 1) return 1;
  return x * y / gcd(x, y);
}