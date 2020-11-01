#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool solve(string s) {
    if(s.size() == 1) { return s == "8"; }
    if(s.size() == 2) {
        if(stoi(s) % 8 == 0) return true;
        swap(s[0], s[1]);
        return stoi(s) % 8 == 0;
    }

    vector<int> cnt(10);
    for(auto &e: s) ++cnt[e - '0'];

    for(int i = 112; i < 1000; i += 8) {
        vector<int> tmp = cnt;
        for(auto &e: to_string(i)) --tmp[e - '0'];
        if(all_of(tmp.begin(), tmp.end(), [](int x){return x >= 0;})) {
            return true;
        }
    }

    return false;
}

int main() {

    string s;
    cin >> s;

    cout << (solve(s) ? "Yes" : "No") << endl;

    return 0;
}