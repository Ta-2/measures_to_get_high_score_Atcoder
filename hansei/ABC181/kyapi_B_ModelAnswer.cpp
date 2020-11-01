#include <iostream>
using namespace std;

using ll = long long;

int main() {

    ll n;
    cin >> n;

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        ans += b*(b+1)/2 - a*(a-1)/2;
    }

    cout << ans << endl;

    return 0;
}