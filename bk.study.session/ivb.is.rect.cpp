/**
 * @file ivw.is.rect
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday January 05 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

bool solve(int a, int b, int c, int d) {
  return (a == b && c == d) || (a == c && b == d) || (a == d && b == c);
}
