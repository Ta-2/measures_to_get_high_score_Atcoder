/**
 * �^����ꂽ��������x�̊֐��ƌ����Ƃ�
 * �L�`�Z�������ł��邱�Ƃ���A
 * ��`��̍ő�l�����߂�ő�l�ƂȂ�
*/

#include <iostream>
#include <cmath>

int main(){

    int a;
    long long b, n;
    std::cin >> a >> b >> n;

    n = std::min(n, b - 1);

    std::cout << (a * n) / b - a * (n / b) << std::endl;

    return 0;
}