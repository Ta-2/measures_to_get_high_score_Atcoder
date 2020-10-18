#include <iostream>
#include <iomanip>
using namespace std;

//fib関数の戻り値の型が__int128_tなので、オーバーロードが必要
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
    __uint128_t memo[1000];                         //fib関数内部で得た結果を一時的に格納する配列

public:
    __uint128_t fib(long long n){                   //128bit整数を使っているので、n = 186まではオーバーフローしない

        if(n <= 1) return n;

        else if(memo[n] != 0) return memo[n];       //ここで計算の重複を避けている

        else{
            return memo[n] = fib(n-1) + fib(n-2);   //フィボナッチ数列の漸化式(an = a(n-1) + a(n-2))を逆行する形で再帰呼び出し
        }
    }

};

int main(){

    long long n;
    cin >> n;

    calc FIB;

    for(int i = 2; i < n; ++i){

        cout  << FIB.fib(i) << " ÷ " << FIB.fib(i-1) << " = ";

        cout << fixed << setprecision(21) << (long double)FIB.fib(i) / FIB.fib(i-1) << endl;
        //フィボナッチ数列のn項目と(n-1)項目の比は黄金比((1+√5)/2 = 1.6180339887498948482045868...)に収束することの確認
    }

    cout << endl;
    cout << fixed << setprecision(21) << (long double)1.6180339887498948482045868L << endl;
    cout << "黄金比↑" << endl;

return 0;
}