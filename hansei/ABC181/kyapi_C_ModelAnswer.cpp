/*
 * 入力をpair型に格納して後から分解するのは
 * アリかなと思った
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for(auto &[x, y]: p) {
        cin >> x >> y;
    }

    for(int i = n; i--; )
    for(int j = i; j--; )
    for(int k = j; k--; ) {
        auto [x1, y1] = p[i];
        auto [x2, y2] = p[j];
        auto [x3, y3] = p[k];
        x1 -= x3;
        x2 -= x3;
        y1 -= y3;
        y2 -= y3;
        if(x1 * y2 == x2 * y1) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}