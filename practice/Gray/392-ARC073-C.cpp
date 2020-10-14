#include <iostream>
#include <vector>
#include <cmath>

int main(){

    int N, T;
    std::cin >> N >> T;

    int ans = 0;

    std::vector<int> t(N);
    for(int i = 0; i < N; ++i){
        std::cin >> t[i];
    }

    for(int i = 1; i < N; ++i){
        ans += std::min(T, t[i] - t[i-1]);
    }

    std::cout << ans + T << std::endl;

return 0;
}