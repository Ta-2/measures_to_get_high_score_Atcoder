/**
 * long double �̌덷�𖄂߂邽�߂�
 * eps ���g����
 * �C�}�C�`�덷�̈�����������Ȃ�
*/

#include <iostream>
#include <cfloat>

constexpr long double eps = DBL_EPSILON;
//������`����Ă��܂���Əo����
//�Ƃ肠���� __DBL_EPSILON__ �ɕς��Ă݂�

int main(){

    long long a;
    long double b;
    std::cin >> a >> b;
    b = b * 100 + eps;
    a *= b;
    std::cout << a / 100 << std::endl;

    return 0;
}