/*
 * 初項 a, 末項 b, 等差 1 の等差数列の和を
 * 全て足し合わせた
*/

#include <iostream>
using namespace std;

using ll = long long;

ll sum(ll a, ll b) {
    return (b-a+1)*(a+b)/2;
}

int main() {

    int n;
    cin >> n;

    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ans += sum(a, b);
    }

    cout << ans << endl;

    return 0;
}