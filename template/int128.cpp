/**
 *  ����A�V�t�g���Z�q�̃I�[�o�[���[�h�̋����͂قƂ�ǂ����ς�킩��Ȃ����A
 *  �Ƃ肠�����A128bit����(�����t���A�����Ȃ�����)�̎����������B
 *
 *  �Q�l���T�C�g:
 *  https://kenkoooo.hatenablog.com/entry/2016/11/30/163533
 *
 *
 *  ��:
 *  VSCode�ł��̃\�[�X�R�[�h���J�����Ƃ��A���炭�u���ʎq "__uint128_t" ����`����Ă��܂���v
 *  �Ɠ{���邪�A����͊���̃��[�N�X�y�[�X��intelliSenseMode��msvc-x64�ɂȂ��Ă���̂������B
 *  (���̂܂܃R���p�C�����Ă�������Ɠ���͂��邪�A)
 *  �������̃G���[�\���𒼂������Ƃ��́A
 *  c_cpp_properties.json��intelliSenseMode�̕�����gcc-x64�ɏ���������K�v������B
 *
 *  ����ƍ��x�́A�uIntelliSense ���[�h gcc-x64 �́A�R���p�C�� �p�X�ƌ݊���������܂���B�v�Ƃ���
 *  �G���[���\�������̂ŁAc_cpp_properties.json��compilerPath�����������Ă�����Ɨǂ��B
 *  (mingw64��g++.exe�͖��Ȃ����������͕�����Ȃ��B)
 *
*/

#include <iostream>
using namespace std;

//__uint128_t�^�̕ϐ���cout�ŏo�͂ł���悤�ɂ���
std::ostream &operator<<(std::ostream &dest, __int128_t value){
    std::ostream::sentry s(dest);

    if(s){
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);     //�z��̖����̂ЂƂ����w���|�C���^

        do{                                         //�i
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
                                                    //��
        }while(tmp != 0);

        if(value < 0){
            --d;                                    //�_
            *d = '-';
        }

        int len = std::end(buffer) - d;             //�R
        if(dest.rdbuf()->sputn(d, len) != len){
            dest.setstate(std::ios_base::badbit);
        }
    }                                               //��

    return dest;
}

//__uint128_t�^�̕ϐ���cout�ŏo�͂ł���悤�ɂ���(�ȉ��A__int128_t�^�ƍ\���͓���)
std::ostream &operator<<(std::ostream &dest, __uint128_t value_u){
    std::ostream::sentry s(dest);

    if(s){
        __uint128_t tmp = value_u < 0 ? -value_u : value_u;
        char buffer[128];
        char *d = std::end(buffer);

        do{
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;

        }while(tmp != 0);

        if(value_u < 0){
            --d;
            *d = '-';
        }

        int len = std::end(buffer) - d;
        if(dest.rdbuf()->sputn(d, len) != len){
            dest.setstate(std::ios_base::badbit);
        }
    }

    return dest;
}

//string -> int128 �ϊ��֐�(�߂�l�̌^��K�v�ɉ����ĕύX����΁A���Ȃ���p���̍����֐����Ǝv��)
__uint128_t Parse(string &s){
    __uint128_t ret = 0;

    bool minus = false;             //���͂��������񂪕������ǂ������i�[
    if(s[0] == '-') minus = true;   //�ꕶ���ڂ�"-"�̎��A�t���O�𗧂Ă�

    for(int i = 0; i < (int)s.length(); ++i){
        if('0' <= s[i] && s[i] <= '9'){     //������0~9�܂ł̐��̂Ƃ��̂ݏ���(�����̂݁u���o�v����悤�ȋ���������)
            ret = 10 * ret + s[i] - '0';    //(10 * ret) + (s[i] - '0')�ƒu���ƌ��₷��
        }
    }

    if(minus) ret *= -1;            //�����A������̐擪��"-"������΁A�}�C�i�X���|����

    return ret;
}

int main(){

    string sd = "170141183460469231731687303715884105727";   // 170141183460469231731687303715884105727  = 2^127 - 1 (__int128_t  : maximum)
    string nd = "-170141183460469231731687303715884105728";  // -170141183460469231731687303715884105728 = -2^127    (__int128_t  : minimum)
    string ud = "340282366920938463463374607431768211455";   // 340282366920938463463374607431768211455  = 2^128 - 1 (__uint128_t : maximum)

    cout << "---string---" << endl;
    cout << sd << endl;             //���͂������̊m�F
    cout << nd << endl;             //���͂������̊m�F
    cout << ud << endl;             //���͂������̊m�F
    cout << endl;

    __int128_t  sx = Parse(sd);     //���l�ɕϊ�
    __int128_t  nx = Parse(nd);     //���l�ɕϊ�
    __uint128_t ux = Parse(ud);     //���l�ɕϊ�

    cout << "---integer---" << endl;
    cout << sx << endl;
    cout << nx << endl;
    cout << ux << endl;
    cout << endl;

    cout << "input(string)  = ";
    string hoge; cin >> hoge;
    __int128_t huga = Parse(hoge);
    cout << "output(int128) = " << huga << endl;

return 0;
}