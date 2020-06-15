/**
 * @file 006.275A - Lights Out.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun Jun 14 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    short int A[3][3], B[3][3];

    // initially all lights are on
    memset(A, 0, sizeof A);

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            B[i][j] = 1;
            int c;
            cin >> c;
            A[i][j] = c & 1;
        }
    }

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if (A[i][j]) {
                B[i][j] = !B[i][j];
                if(i - 1 >= 0)
                    B[i - 1][j] ^= 1;
                if(j - 1 >= 0)
                    B[i][j - 1] ^= 1;
                if(i + 1 < 3)
                    B[i + 1][j] ^= 1;
                if(j + 1 < 3)
                    B[i][j + 1] ^= 1;
            }
        }
    }

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            cout << B[i][j];
        }
        cout << endl;
    }
    return 0;
}