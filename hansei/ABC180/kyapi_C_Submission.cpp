#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

//愚直にpush -> O(N)
//ペアとなる約数を同時にpush -> O(√N)
vector<ll> divisors(ll n) {
    vector<ll> res;
    for(ll i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            res.push_back(i);
            if(n/i != i) res.push_back(n/i);    //重複をはじいてpushしている
        }
    }

    sort(res.begin(), res.end());               //昇順にソート
    return res;
}

int main() {

    ll n;
    cin >> n;

    vector<ll> ret = divisors(n);

    for(auto &e : ret) cout << e << endl;

return 0;
}