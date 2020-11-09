#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int Max = 0;
    int ans = -1;
    for (int i = 2; i <= 1000; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] % i == 0) ++cnt;
        }
        if (Max < cnt) {
            Max = cnt;
            ans = i;
        }
    }

    cout << ans << '\n';

    return 0;
}