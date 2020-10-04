#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

//�r�b�g�̐���ɂ��ăt�B���^�[���l����
int main(){
    constexpr int n = 6;                //�����r�b�g����萔�Œ�`
    const string s = "000001";          //�t�B���^�[�ƂȂ�bit���string�Œ�`
    bitset <n> filter(s);               //�t�B���^�[��bitset�Ő���


#ifdef __LOCAL__
    cerr << "n -> " << n << endl;       //debug
    cerr << "filter -> " << s << endl;  //debug
#endif


//����������s��
    for(int bit = 0; bit < (1 << n); ++bit){
        vector<int> S;                  //�S�Ă̑g�ݍ��킹�������ł܂Ƃ߂�
        S.reserve(n);                   //S��push_back���鎞�ɁA���ʂȃ������̊m�ۂ�h��(����͂قږ��Ӗ�)
        bitset<n> now_bit(bit);         //���݂�bit��bitset�ɕϊ�

    //�����ŁAfilter��bit�ɗ����Ă���t���O���ЂƂł��d�����Ă���ꍇ�A�������Ƃ΂��B
        if((now_bit & filter).count()) continue;

    //(�t�B���^�[��)�d�����Ă��Ȃ��g�ݍ��킹�Ƀt�B���^�[���|����
        now_bit |= filter;

    //�g�ݍ��킹��S��push_back���Ă���
        for(int i = 0; i < n; ++i){
            bitset<n> check(1);         //��r�p��1��bitset��p��

            if((now_bit & (check << i)).count()){
                S.push_back(i);         //�v�f��push_back���Ă���
            }
        }

    //(�t�B���^�[���o��)�S�Ă̑g�ݍ��킹��\��
        cout << bit << "(�Ԗ�): { ";
        for(int i = 0; i < (int)S.size(); ++i) cout << S[i] << " ";
        cout << "}" << endl;
    }

  return 0;
}