#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

vector<string> split(string S, char ch) {
    vector<string> ss;
    int n = S.size(), s = 0, l = 0;  // start and length of string
    for (int i = 0; i < n; ++i) {
        if (S[i] == ch) {
            string k = S.substr(s, l);
            if (!k.empty()) {
                ss.eb(k);
            }
            s = i + 1, l = 0;
        } else {
            ++l;
        }
    }

    ss.eb(S.substr(s, l));
    return ss;
}

int main() {
    string parag = "The quick Brown fox jumps over the lazy dog, and the dog fucked her";
    for (string ss : split(parag, ',')) {
        for (string s : split(ss, ' ')) {
            cout << s << '<' << endl;
        }
        cout << endl;
    }
}