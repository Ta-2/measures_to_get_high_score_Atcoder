/*
 * 端点と0の大小関係を調べるという
 * なんだか受験数学を彷彿とさせるような解法。
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, l; cin >> n >> l;

    vector<int> p(n);
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        p[i] = l + i;
        sum += p[i];
    }

    int eat = 0;
    if     (*(p.begin())   >= 0)    eat = *(p.begin());
    else if(*(p.end() - 1) <= 0)    eat = *(p.end() - 1);
    else                            eat = 0;

    cout << sum - eat << endl;

    return 0;
}