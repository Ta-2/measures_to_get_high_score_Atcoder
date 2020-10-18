#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

using ll = long long;

int main(){
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; ++i) cin >> x[i];

    ll ans1 = 0;
    for(int i = 0; i < n; ++i) ans1 += abs(x[i]);

    cout << ans1 << endl;


    ll ans2 = 0;
    for(int i = 0; i < n; ++i) ans2 += abs(x[i])*(ll)abs(x[i]);

    cout << sqrt(ans2) << endl;

    int ans3 = 0;
    for(int i = 0; i < n; ++i) ans3 = max(ans3, abs(x[i]));

    cout << ans3 << endl;
}