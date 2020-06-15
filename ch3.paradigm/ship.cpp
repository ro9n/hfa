//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef pair<int, int> ii;

ii NE[26 << 1], SW[26 << 1];

// parses the position string to {x, y}
ii parse(const string &s) {
    int x, y, n = s.size();
    sscanf(s.c_str(), "%d", &x);
    y = s[n - 1] - 'A' + 1;

    return {x, y};
}

int parseShips(const string &S) {
    int i = 0, l = 0, n = S.size(), space = -1;

    while (l < n) {
        int r = l + 1;
        while (r < n && S[r] != ',') {
            if (S[r] == ' ') space = r;
            ++r;
        }
        // [l, r)
        string ne = S.substr(l, space - l), sw = S.substr(space + 1, r - space - 1);
        NE[i] = parse(ne), SW[i] = parse(sw), ++i;
        l = r + 1;
    }

    return i;
}

string solution(int N, string &S, string &T) {
    // parse ships
    int ships = parseShips(S);

    // for each ship
    map<ii, int> position;
    int lives[ships], elvlives[ships];
    for (int i = 0; i < ships; ++i) {
        for (int j = NE[i].first; j < SW[i].first - 1; ++j) {
            for (int k = NE[i].second; k <= SW[i].second; ++k) {
                //                cout << j << k << endl;
                position[{j, k}] = i;
            }
        }
        lives[i] = elvlives[i] = (SW[i].second - NE[i].second + 1) * (SW[i].first - NE[i].first + 1);
        cout << lives[i] << endl;
    }

    int start = 0;
    for (int i = start; i < T.size(); ++i) {
        while (T[i] != ' ' && i < T.size()) ++i;
        ii attack = parse(T.substr(start, i));
        int ship = position[attack];
        --elvlives[ship];
        start = i + 1;
    }

    int sunk = 0, damaged = 0;
    for (int i = 0; i < ships; ++i) {
        cout << lives[i] << ' ' << elvlives[i] << endl;
        if (lives[i] == elvlives[i] && elvlives[i] == 0)
            ++sunk;
        else if (lives[i] > elvlives[i])
            ++damaged;
    }

    return to_string(sunk) + "," + to_string(damaged);
}

int main() {
    string S = "1B 2C,2D 4D",
           T = "2B 2D 3D 4D 4A";
    cout << solution(4, S, T) << endl;
}
