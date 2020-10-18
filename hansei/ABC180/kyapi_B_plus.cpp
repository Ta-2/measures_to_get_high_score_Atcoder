#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

using ll = long long;

int main() {

    int n;
    cin >> n;
    ll ans1 = 0, ans2 = 0, ans3 = 0;

    //vectorを使わなくても解ける(前から順に処理していくため)

    for(int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        x = abs(x);
        ans1 += x;
        ans2 += x * x;
        ans3 = max(ans3, x);
    }

    cout << ans1 << endl;
    cout << fixed << setprecision(10) << sqrt(ans2) << endl;
    cout << ans3 << endl;

return 0;
}