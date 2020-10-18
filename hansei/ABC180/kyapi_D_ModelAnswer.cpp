#include <iostream>
using namespace std;

using ll = long long;

int main(){

    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    ll ans = 0;

    while(true) {
        if((ll)1e18 / a < x) break; //オーバーフローをはじく(1e18はyの制約の最大値でもある)
        if(y <= x * a) break;       //y以上をはじく
        if(x + b < x * a) break;    //増分がx + bよりも大きくなった時ループを出る

        x *= a;
        ++ans;
    }

    ans += (y - 1 - x) / b;         //bを足せる回数を数える

    cout << ans << endl;

return 0;
}