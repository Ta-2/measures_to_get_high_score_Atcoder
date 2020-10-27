#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    vector<int> l(n);
    vector<int> d(n+1);

    for(int i = 0; i < n; ++i) {
        cin >> l[i];

        if(i >= 1) {
            d[i] = d[i-1] + l[i-1];
        }
    }

    d[n] = d[n-1] + l[n-1];

    cout
    << distance(d.begin(), (upper_bound(d.begin(), d.end(), x)))
    << endl;

    return 0;
}