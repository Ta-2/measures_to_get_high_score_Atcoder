//※模範解答には関係ない

#include <iostream>
using namespace std;

using ll = long long;

int main(){

cout << (ll)2e18 << endl;   //2000000000000000000
cout << (int)2e18 << endl;  //2147483647
cout << (int)2e9 << endl;   //2000000000

return 0;
}

/*
 *  キャストする型によって値が変わってしまう点に注意
*/