#include <iostream>
#include <vector>
using namespace std;

template <typename Ty1, typename Ty2>
inline bool chmax(Ty1 &a, Ty2 b)
{ return a < b && (a = b, true); }

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int cnt = 0;
    int ans = 0;
    for(int k = 2; k <= 1000; ++k) {
        int tmp = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] % k == 0) ++tmp;
        }
        if(chmax(cnt, tmp)) {
            ans = k;
        }
    }

    cout << ans << '\n';

    return;
}