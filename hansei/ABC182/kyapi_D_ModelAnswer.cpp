#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
constexpr int maxN = (int)2e5 + 5;

int main() {

    int n;
    cin >> n;
    vector<ll> a(maxN), sum(maxN);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum[i] = (i > 0 ? sum[i - 1] + a[i] : a[i]);
    }

    ll ans = 0;
    ll Max = 0;
    ll now = 0;

    for(int i = 0; i < n; ++i){
        if(Max < sum[i]) { Max = sum[i]; }
        ans = max(ans, now + Max);
        now += sum[i];
    }

    cout << ans << '\n';

    return 0;
}