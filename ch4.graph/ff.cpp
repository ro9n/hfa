#include <bits/stdc++.h>

using namespace std;

class Solution {
    // L T R B
    int dc[4] = {-1, 0, +1, 0}, dr[4] = {0, -1, 0, +1};

    void ff(vector<vector<int>>& m, int r, int c, int c1, int c2) {
        if (r < 0 || m.size() <= r || c < 0 || m[0].size() <= c)
            return;

        if (m[r][c] != c1) return;

        m[r][c] = c2;

        for (int i = 0; i < 4; ++i) {
            int rr = r + dr[i], cc = c + dc[i];
            ff(m, rr, cc, c1, c2);
        }
    }

   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            ff(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};

int main() {
    auto s = new Solution();
    vector<vector<int>> image = {{0, 0, 0}, {0, 1, 1}};
    s->floodFill(image, 1, 1, 1);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << image[i][j] << ' ';
        }

        cout << endl;
    }
}