/**
 * 入力から重複をはじいても問題ないので、setを使用
 * 入力の範囲が狭いので、全ての数について最小値を
 * 調べ上げる方針で通る
*/

#include <iostream>
#include <set>

constexpr int inf = 1<<30;

int main(){

    int x, n;
    std::cin >> x >> n;
    std::set<int> p;
    for(int i = 0; i < n; ++i){
        int t;
        std::cin >> t;
        p.insert(t);
    }

    int dif = inf;
    int ans = inf;
    for(int i = 0; i <= 101; ++i){
        if(p.count(i)) continue;
        int d = std::abs(x - i);
        if(d < dif){
            dif = d;
            ans = i;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}