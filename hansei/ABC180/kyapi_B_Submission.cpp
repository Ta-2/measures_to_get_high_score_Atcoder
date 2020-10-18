#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

using ll = long long;

int main() {

    int n;
    cin >> n;
    ll ans1 = 0, ans2 = 0, ans3 = 0;

    vector<ll> x(n);
    vector<ll> x2(n);   // <- 使わなかった

    for(int i = 0; i < n; ++i) {
        cin >> x[i];
        x[i] = abs(x[i]);
        ans1 += x[i];
        ans2 += x[i] * x[i];
        ans3 = max(ans3, x[i]);
    }

    cout << ans1 << endl;
    cout << fixed << setprecision(10) << sqrt(ans2) << endl;
    cout << ans3 << endl;

return 0;
}