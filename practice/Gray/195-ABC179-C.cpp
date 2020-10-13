/**
 * a, b ‚ğŒÅ’è‚µ‚½Ac ‚ÍˆêˆÓ‚É’è‚Ü‚é(O(n^2))
 * a ‚ğŒÅ’è‚µ‚½Ab, c ‚ÍˆêˆÓ‚É’è‚Ü‚é(O(n))
*/

#include <iostream>

int main(){

    int n;
    std::cin >> n;
    int ans = 0;

    for(int i = 1; i < n; ++i){
        ans += (n - 1) / i;     //Šea‚É‘Î‚·‚éb‚ÌŒÂ”‚ğ‘«‚µ‡‚í‚¹‚é
    }

    std::cout << ans << std::endl;

    return 0;
}