/**
 * �ݐϘa(�ł����Ă�̂��H)���g�����
 * sum��0�ȏ�MOD�ȉ��Ɏ��܂�悤�ɒ��ӂ��Ȃ���΂����Ȃ�
 * (�R���̂�����2, 3��WA������)
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