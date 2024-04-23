//------------ヘッダーインクルード------------
#include <bits/stdc++.h>
#include <stdio.h>
#include <cmath>
#include <stdarg.h>
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
typedef long double ld;
#define INIF 1e9;
#define MOD 1000000007;
#define ALL(v) (v).begin(), (v).end()
//------------vectorマクロ定義------------
#define v(Type) vector<Type>
#define vv(Type) vector<vector<Type>>
#define vvv(Type) vector<vector<vector<Type>>>
#define v_i(Type, d_v, d_n) v(Type) d_v(d_n)
#define vv_i(Type, d_v, d_m, d_n) vv(Type) d_v(d_m, v(Type)(d_n))
#define vvv_i(Type, d_v, d_l, d_m, d_n) vvv(Type) d_v (d_l, vv(Type)(d_m, v(Type)(d_n)))
//------------forマクロ定義------------
#define rep1(d_i, d_n) for(int d_i = 0; d_i < d_n; d_i++)
#define rep2(d_i, d_m, d_n) for(int d_i = d_m; d_i < d_n; d_i++)
#define rep3(d_i, d_l, d_m, d_n) for(int d_i = d_l; d_i < d_m; d_i+=d_n)
#define rep_overload3(a, b, c, d, e, ...) e
#define rep(...) rep_overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

#define fe(d_i, STL) for(auto d_i: (STL))
//------------ioマクロ定義------------
#define co cout<<
#define en <<endl
#define in cin>>
#define br co "" en
#define pr(value) ","<<#value<<": "<<value
#define sn(value) #value, value

template<class... T>
void input(T&... a){
  (cin >> ... >> a);
}
#define in_v(type, ...)\
    type __VA_ARGS__;\
    input(__VA_ARGS__);

#define in_l(type, d_l, d_v)\
    v(type) d_l( d_v );\
    rep(d_i, d_v) in(d_l[d_i]);
    
#define in_vl(type_v, d_v, type_l, d_l)\
    in_v(type_v, d_v);\
    in_l(type_l, d_l, d_v);

//------------表示マクロ定義------------
void print_name(string name){
  co name << ": ";
}
template<class T, class... Ts>
void print_value(T head, Ts... body){
  co head;
  (cout << ... << (cout << ' ' , body));
  br;
}
#define p(...)\
    print_name(#__VA_ARGS__);\
    print_value(__VA_ARGS__);

template<class Type>
void print_value2(string name, Type value){
  int num = 0;
  //fe(i, value)co name << "[" << num++ << "]:"  << i << ", ";
  co name << ": ";
  fe(i, value)co i << ", ";
  br;
}
#define p_l(Type, value) print_value2<Type>(sn(value))

void print_value3(string name, auto value){
  int num = 0;
  fe(i, value)co name << "[" << num++ << "]:" << i en;
}
#define p_lb(value) print_value3(sn(value))
//------------main------------

int main(){
  v(int) a({1,2,3});
  fe(i, a) co i en;
  int i = 0;
  p(i);
  
  int num = 0;
  vector<int> array(5);
  fe(&i, array)i = num++;
  fe(i, array)co i en;
  p_l(v(int), array);
  
  rep(j, 5){co j en;}
  rep2(i, 5, 10)co i en;
  repr(i, 5)co i en;
  
  in_vl(iter, arr, int);
  p(iter);
  p_l(v(int), arr);
  
  return 0;
}
