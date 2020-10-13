/**
 * long double の誤差を埋めるために
 * eps を使った
 * イマイチ誤差の扱いが分からない
*/

#include <iostream>
#include <cfloat>

constexpr long double eps = DBL_EPSILON;
//もし定義されていませんと出たら
//とりあえず __DBL_EPSILON__ に変えてみる

int main(){

    long long a;
    long double b;
    std::cin >> a >> b;
    b = b * 100 + eps;
    a *= b;
    std::cout << a / 100 << std::endl;

    return 0;
}