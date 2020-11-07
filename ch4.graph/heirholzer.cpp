/**
 * @file heirholzer
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday October 28 2020
 *
 * @brief Hierholzer’s Algorithm for "directed" graph
 * 
 * Using Heirholzer’s Algorithm, we can find the circuit/path in O(E), i.e., linear time.
 * 
 *    → Choose any starting vertex v, and follow a trail of edges from that vertex until 
 * returning to v. It is not possible to get stuck at any vertex other than v, because 
 * indegree and outdegree of every vertex must be same, when the trail enters 
 * another vertex w there must be an unused edge leaving w.
 * 
 * The tour formed in this way is a closed tour, but may not cover all the 
 * vertices and edges of the initial graph.
 * 
 *    → As long as there exists a vertex u that belongs to the current tour, but that has adjacent
 * edges not part of the tour, start another trail from u, following unused edges until 
 * returning to u, and join the tour formed in this way to the previous tour.
 * 
 * For undirected multigraph with loops
 *  FindEulerPath(V)
 *   1. iterate through all the edges outgoing from vertex V;
 *        remove this edge from the graph,
 *        and call FindEulerPath from the second end of this edge;
 *   2. add vertex V to the answer.
 * 
 * Non recursive:
 * stack St;
 * put start vertex in St;
 * until St is empty
 *   let V be the value at the top of St;
 *   if degree(V) = 0, then
 *     add V to the answer;
 *     remove V from the top of St;
 *   otherwise
 *     find any edge coming out of V;
 *     remove it from the graph;
 *     put the second end of this edge in St;
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vector<vi> g; vi outdeg;

void dfs() {
  if(g.empty()) return; // empty graph
  for(int u = 0; u < g.size(); ++u) {
    outdeg[u] = g[u].size(); // outdegree of vertex u
  }
}

int main() {
  return 0;
}
