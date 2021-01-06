/**
 * @file careercup.sorting.names
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday January 06 2021
 *
 * @brief Given a list/array of names(String) sort them such that each name is followed by a name which starts with the last character of the previous name. 
 * # input [ Luis Hector Selena Emmanuel Amish ] 
 * # output: [ Emmanuel Luis Selena Amish Hector ]
 */

#include <bits/stdc++.h>

using namespace std;

inline int hs(const string& s) {
  return toupper(s[0]) - 65;
}

inline int he(const string& s) {
  return toupper(s[s.size() - 1]) - 65;
}

int main() {
  vector<string> names{"Luis", "Hector", "Selena", "Emmanuel", "Amish"};
  unordered_map<int, string> start, end;

  for (auto name : names) {
    start[hs(name)] = name, end[he(name)] = name;
  }

  vector<string> ans;

  for (auto entry : start) {
    if (!end.count(entry.first)) {
      // indegree(etnry) = 0
      string s = entry.second;
      while (s != "") {
        ans.push_back(s);
        s = start[he(s)];
      }
      break;
    }
  }

  for (auto name : ans) cout << name << ',';
  cout << endl;

  return 0;
}
