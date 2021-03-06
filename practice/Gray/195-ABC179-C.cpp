/**
 * a, b を固定した時、c は一意に定まる(O(n^2))
 * a を固定した時、b, c は一意に定まる(O(n))
*/

#include <iostream>

int main(){

    int n;
    std::cin >> n;
    int ans = 0;

    for(int i = 1; i < n; ++i){
        ans += (n - 1) / i;     //各aに対するbの個数を足し合わせる
    }

    std::cout << ans << std::endl;

    return 0;
}