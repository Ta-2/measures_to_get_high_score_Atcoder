#include <iostream>
#include <iomanip>
using namespace std;

//fib�֐��̖߂�l�̌^��__int128_t�Ȃ̂ŁA�I�[�o�[���[�h���K�v
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


class calc{
private:
    __uint128_t memo[1000];                         //fib�֐������œ������ʂ��ꎞ�I�Ɋi�[����z��

public:
    __uint128_t fib(long long n){                   //128bit�������g���Ă���̂ŁAn = 186�܂ł̓I�[�o�[�t���[���Ȃ�

        if(n <= 1) return n;

        else if(memo[n] != 0) return memo[n];       //�����Ōv�Z�̏d��������Ă���

        else{
            return memo[n] = fib(n-1) + fib(n-2);   //�t�B�{�i�b�`����̑Q����(an = a(n-1) + a(n-2))���t�s����`�ōċA�Ăяo��
        }
    }

};

int main(){

    long long n;
    cin >> n;

    calc FIB;

    for(int i = 2; i < n; ++i){

        cout  << FIB.fib(i) << " �� " << FIB.fib(i-1) << " = ";

        cout << fixed << setprecision(21) << (long double)FIB.fib(i) / FIB.fib(i-1) << endl;
        //�t�B�{�i�b�`�����n���ڂ�(n-1)���ڂ̔�͉�����((1+��5)/2 = 1.6180339887498948482045868...)�Ɏ������邱�Ƃ̊m�F
    }

    cout << endl;
    cout << fixed << setprecision(21) << (long double)1.6180339887498948482045868L << endl;
    cout << "�����䁪" << endl;

return 0;
}