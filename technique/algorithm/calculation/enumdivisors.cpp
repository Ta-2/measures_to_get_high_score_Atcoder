/*約数列挙*/

#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<ll> EnumDivisors(ll N) {
    vector<ll> ret;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            ret.push_back(i);
            if (N/i != i) ret.push_back(N/i);
        }
    }

    sort(ret.begin(), ret.end());

    return ret;
}