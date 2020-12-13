/**
 * @file all.paths
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday December 13 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define WHITE 0
#define GREY  1
#define BLACK 2

#define pb push_back

// v ^ v expo
// v! for complete graph
int main() {
  // vector<vi> g = {
  //     {},
  //     {2, 3},
  //     {3, 4},
  //     {4, 5},
  //     {5},
  //     {4}};

  vector<vi> g = {
      {1, 2},
      {0, 2},
      {0}};
  vi color(6, WHITE), current_path;
  vector<vi> simple_paths;

  function<void(int, int)> dfs = [&](int s, int d) -> void {
    if (color[s] != WHITE) return;
    color[s] = GREY;
    current_path.pb(s);

    if (s == d) simple_paths.pb(current_path);
    else
      for (auto v : g[s]) dfs(v, d);

    color[s] = WHITE, current_path.pop_back();
  };

  // dfs(0, 2);

  current_path.push_back(0);
  for(auto s: g[0])
    dfs(s, 0);

  for (auto path : simple_paths) {
    cout << '{';
    for (auto node : path) cout << node;
    cout << '}' << endl;
  }

  return 0;
}
