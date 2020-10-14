/**
 * https://atcoder.jp/contests/caddi2018b/tasks/caddi2018_a
 *
 * 考えられる最大公約数のうちもっとも大きいものを求める問題
 * 実際には、(ざっくり言うと)gcd^N <= Pを満たす最大のgcdを求める問題
 *
 * 注意点は、Pがgcdで割り切れる条件を守っているかどうか
 *
*/

#include <iostream>
#include <cmath>

int main(){

    long long n, p;
    std::cin >> n >> p;

    if(n == 1){
        std::cout << p << std::endl;
        return 0;
    }

    long long ans = 1;

    //ans = 1に初期化しているので、i = 2から始めていい
    for(int i = 2; i <= 1000010; ++i){
        long long kn = std::pow(i, n);
        if((p % kn) == 0){
            ans = i;
        }
        if(p < kn) break;
    }

    std::cout << ans << std::endl;

return 0;
}