/*
 * bit全探索で愚直にシミュレーションした。
 * O(2^n)  10^6 なので間に合う。
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n), c(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    for(int i = 0; i < n; ++i) cin >> c[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << n); ++bit) {
        int sumv = 0;
        int sumc = 0;
        for(int i = 0; i < n; ++i) {
            if(bit & (1 << i)) {
                sumv += v[i];
                sumc += c[i];
            }
        }

        ans = max(ans, sumv - sumc);
    }

    cout << ans << endl;

    return 0;
}