#include <iostream>
#include <string>

int main(){

    long long n;
    std::cin >> n;

    std::string ans = "";

    //大きい位から順にansへ入れる
    while(n > 0){
        --n;
        char c = (n % 26) + 'a';
        ans += c;
        n /= 26;
    }

    //小さい位から順に出力する
    for(int i = ans.size() - 1; i >= 0; --i){
        std::cout << ans[i];
    }

    std::cout << std::endl;

    return 0;
}