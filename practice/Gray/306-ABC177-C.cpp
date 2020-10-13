/**
 * —ÝÏ˜a(‚Å‚ ‚Á‚Ä‚é‚Ì‚©H)‚ðŽg‚¤–â‘è
 * sum‚ª0ˆÈãMODˆÈ‰º‚ÉŽû‚Ü‚é‚æ‚¤‚É’ˆÓ‚µ‚È‚¯‚ê‚Î‚¢‚¯‚È‚¢
 * (ƒRƒŒ‚Ì‚¹‚¢‚Å2, 3‰ñWA‹ò‚ç‚Á‚½)
*/

#include <iostream>

constexpr int MOD = (int)1e9 + 7;

int main(){

    int n;
    std::cin >> n;
    long long a[200005];
    long long sum = 0;
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
        sum += a[i];
        if(MOD <= sum) sum -= MOD;
    }

    long long ans = 0;
    for(int i = 0; i < n; ++i){
        sum -= a[i];
        if(sum < 0) sum += MOD;
        ans += a[i] * sum % MOD;
    }

    std::cout << ans % MOD << std::endl;

    return 0;
}