#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<int> cnt(3);
    while(n) {
        ++cnt[n % 10 % 3];
        n /= 10;
    }

    int cur = (cnt[1] + 2 * cnt[2]) % 3;
    int digit = cnt[0] + cnt[1] + cnt[2];

    int ans;

    if(cur == 0) {
        ans = 0;
    }

    else if(cur == 1) {
        if(cnt[1] > 0) {
            ans = (digit == 1 ? -1 : 1);
        }
        else {
            ans = (digit == 2 ? -1 : 2);
        }
    }

    else {
        if(cnt[2] > 0) {
            ans = (digit == 1 ? -1 : 1);
        }
        else {
            ans = (digit == 2 ? -1 : 2);
        }
    }

    cout << ans << '\n';

    return 0;
}