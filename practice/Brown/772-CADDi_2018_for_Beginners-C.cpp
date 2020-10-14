/**
 * https://atcoder.jp/contests/caddi2018b/tasks/caddi2018_a
 *
 * �l������ő���񐔂̂��������Ƃ��傫�����̂����߂���
 * ���ۂɂ́A(�������茾����)gcd^N <= P�𖞂����ő��gcd�����߂���
 *
 * ���ӓ_�́AP��gcd�Ŋ���؂�����������Ă��邩�ǂ���
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

    //ans = 1�ɏ��������Ă���̂ŁAi = 2����n�߂Ă���
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