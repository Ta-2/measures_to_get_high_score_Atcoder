//------------ヘッダーインクルード------------
#include <stdio.h>
#include <stdarg.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
//#include <pair>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
//------------型マクロ定義------------
typedef long l;
typedef long long ll;
#define INIF 1e9;
#define MOD 1000000007;
#define ALL(v) (v).begin(), (v).end()
//------------vectorマクロ定義------------
#define v(Type) vector<Type>
#define vv(Type) vector<vector<Type>>
#define vvv(Type) vector<vector<vector<Type>>>
#define vini(n, m) ((n), (m))
//------------forマクロ定義------------
#define rep(i, n) for(int i = 0; (i) < (n); (i)++)
#define rep2(i, m, n) for(int i = (m); (i) < (n); i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define fe(i, STL) for(auto i: (STL))
//------------ioマクロ定義------------
#define co cout<<
#define en <<endl
#define br co "" en
#define pr(value) ","<<#value<<": "<<value
#define sn(value) #value,value
#define setpre(n) fixed<<setprecision(n)<<

template<class Type>
void print_value(string name, Type value){co name << ":" << value;}
#define pri(value) print_value(sn(value))

template<class Type>
void print_value2(string name, Type value, int flag){
  int num = 0;
  if(flag == 0){
    fe(i, value)co name << "[" << num++ << "]:"  << i << ", ";
    br;
  }
  else fe(i, value)co i en;
}
#define pri2(Type, value, flag) print_value2<Type>(sn(value), (flag))
//------------main------------

int main(){
  v(int) a(3);
  fe(i, a) co i en;
  int i = 0;
  double pi = 3.1415926535897932384626433832795;
  pri(i);
  
  int num = 0;
  vector<int> array(5);
  fe(&i, array)i = num++;
  fe(i, array)co i en;
  
  co "pri2: 0" en;
  pri2(vector<int>, array, 0);
  co "pri2: 1" en;
  pri2(vector<int>, array, 1);
  
  co pi en;
  co setpre(15) pi en;
  
  rep(j, 5){co j en;}
  rep2(i, 5, 10)co i en;
  repr(i, 5)co i en;
  
  return 0;
}