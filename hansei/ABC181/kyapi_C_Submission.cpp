/*
 * 「傾きが等しいとき、同一直線状にある」
 * という条件に気付いた後、
 * 『傾きの等式の分母を払えば誤差をなくせる』
 * ことに気付くのが早ければ、更にスコアが伸びていた
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0 ; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            int mx = x[j] - x[i];
            int my = y[j] - y[i];
            for(int k = j+1; k < n; ++k) {
                if(mx*(y[k]-y[i]) == my*(x[k]-x[i])) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}