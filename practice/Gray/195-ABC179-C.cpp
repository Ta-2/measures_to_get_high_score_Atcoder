/**
 * a, b ���Œ肵�����Ac �͈�ӂɒ�܂�(O(n^2))
 * a ���Œ肵�����Ab, c �͈�ӂɒ�܂�(O(n))
*/

#include <iostream>

int main(){

    int n;
    std::cin >> n;
    int ans = 0;

    for(int i = 1; i < n; ++i){
        ans += (n - 1) / i;     //�ea�ɑ΂���b�̌��𑫂����킹��
    }

    std::cout << ans << std::endl;

    return 0;
}