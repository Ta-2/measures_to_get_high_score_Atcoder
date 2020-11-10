/*
 * こっちの方がC問題よりあっさり理解できてしまった…。
 * route_max配列の初期化部分だけ自力では上手く実装は出来なかったが
 * それ以外はほぼ何も見ずに実装したので実質自力AC取っ(音声はここで途絶えている
*/

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
constexpr int INF = (int)1e9;

int main() {

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> route(n);
    vector<ll> route_max(n);
    ll tmp = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        tmp += a[i];
        route[i] = tmp;
    }

    ll tmp2 = 0;
    for(int i = 0; i < n; ++i) {
        if(route[i] > tmp2) {
            tmp2 = route[i];
        }
        route_max[i] = tmp2;
    }

    ll ans = -INF;
    ll now = 0;
    for(int i = 0; i < n; ++i) {
        if(now + route_max[i] > ans) {
            ans = now + route_max[i];
        }
        now += route[i];
    }

    cout << ans << endl;

    return 0;
}