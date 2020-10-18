#include <iostream>
#include <set>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;

    set<ll> ans;
    for(ll d = 1; d * d <= n; ++d) {
        if(n % d == 0) {
            ans.insert(d);
            ans.insert(n/d);    //ここで同時に重複もはじいている
        }
    }

    for(auto x : ans) cout << x << endl;
}