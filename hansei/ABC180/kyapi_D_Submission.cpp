#include <iostream>
using namespace std;

using ll = long long;

int main(){

    ll x, y; cin >> x >> y;
    ll a, b; cin >> a >> b;

    ll ans = 0;
    while(true) {

        //<- if((ll)1e18 / a < x) break;　が必要

        if(min(x * a, x + b) >= y) {    //２.ここのminと↓
            cout << ans << endl;
            return 0;
        }

        if(x * a >= x + b) break;       //１.これを書いている時点で↑
        x = min(x * a, x + b);          //３.ここのminは必要なかった
        ++ans;
    }

    ans += (y - (x + 1)) / b;

    cout << ans << endl;

return 0;
}