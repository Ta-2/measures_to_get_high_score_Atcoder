#include <iostream>

namespace kya{

template<typename Ty>
Ty gcd(Ty a, Ty b){
    return b ? gcd(b, a % b) : a;
}

}

/**
 * -関数の仕組み-
 * 1. bが0の時、aを返す
 * 2. bが0以外の時、再帰呼び出しを行う
 * (aが割られる数, bが割る数)
 *
 * -gcd(b, a % b)の意味-
 *  bを割られる数に持ってきて、
 *  aをbで割った余りを割る数に持ってきている
 *
 * -まとめ-
 * つまりこの関数は、
 * 「割る数が0になる(aがbで割り切れる)まで割り続け、
 *  0になった時の割られる数(つまりaを割り切った数)を返す」
 *  関数となる。
 *
 */

int main(){
    int a, b;
    std::cin >> a >> b;

    std::cout << kya::gcd(a, b) << std::endl;
}