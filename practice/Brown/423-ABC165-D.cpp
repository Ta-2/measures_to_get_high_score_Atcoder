/**
 * 与えられた条件式をxの関数と見たとき
 * 広義短調増加であることから、
 * 定義域の最大値が求める最大値となる
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