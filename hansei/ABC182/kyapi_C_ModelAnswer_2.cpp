/*
 * 2^18 ~= 10^6 なので、bit全探索で間に合う。
 * (bit全探索では無理だと勘違いしていた)
*/

#include <iostream>
#include <string>
using namespace std;

using ll = long long;
constexpr ll INF = 1000000001;

template<class T>
inline bool chmin(T &a, const T &b)
{ if (a > b) { a = b; return true; } return false; }

int main() {

    string s;
    cin >> s;
    int k = s.size();

    int ans = INF;
    for(int i = 0; i < (1 << k); ++i) {
        int tmp = 0;
        int cnt = 0;
        for(int j = 0; j < k; ++j) {
            if (i & (1 << j)) {
                tmp += s[j] - '0';
            }
            else {
                ++cnt;
            }
        }
        if (tmp % 3 == 0) {
            if (cnt != k) {
                chmin(ans, cnt);
            }
        }
    }

    if (ans == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }
}