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

// We’ll consider the worst-case scenario, where the graph is complete, meaning there’s an edge between every pair of vertices. In this case, it turns out the problem is likely to find a permutation of vertices to visit them.
// For each permutation of vertices, there is a corresponding path. Hence, the complexity is O(|V|!), where |V| is the number of vertices and |V|! is the factorial of the number of vertices.
// This complexity is enormous, of course, but this shouldn’t be surprising because we’re using a backtracking approach.

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
