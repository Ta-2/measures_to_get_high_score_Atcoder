/**
 *  エラトステネスの篩を応用した実装
 */

#include <iostream>

int cnt[1000005];

int main(){

    int n;
    std::cin >> n;

    for(int i = 0; i < n; ++i){
        int x;
        std::cin >> x;
        cnt[x]++;
    }

    int ans = 0;

    for(int i = 1; i <= 1000000; ++i){
        if(cnt[i] == 0) continue;

        for(int j = i + i; j <= 1000000; j += i){
            cnt[j] = 2;
        }
        if(cnt[i] == 1) ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}