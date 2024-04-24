//------------ヘッダーインクルード------------
#include <bits/stdc++.h>
#include <stdio.h>
//#include <cmath>
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
#include <limits.h>
using namespace std;
//------------型マクロ定義------------
typedef long l;
typedef long long ll;
typedef long double ld;
#define INF 1e9;
#define MOD 1000000007;
#define ALL(v) (v).begin(), (v).end()
//------------vectorマクロ定義------------
#define v(Type) vector<Type>
#define vv(Type) vector<vector<Type>>
#define vvv(Type) vector<vector<vector<Type>>>

#define v_i1(Type, d_v, d_n)        v(Type) d_v(d_n)
#define v_i2(Type, d_v, d_n, v_ini) v(Type) d_v(d_n, v_ini)
#define v_i_overload2(a, b, c, d, e, ...) e
#define v_i(...) rep_overload3(__VA_ARGS__, v_i2, v_i1)(__VA_ARGS__)

#define vv_i1(Type, d_v, d_m, d_n)        vv(Type) d_v(d_m, v(Type)(d_n))
#define vv_i2(Type, d_v, d_m, d_n, v_ini) vv(Type) d_v(d_m, v(Type)(d_n, v_ini))
#define vv_i_overload2(a, b, c, d, e, f, ...) f
#define vv_i(...) vv_i_overload2(__VA_ARGS__, vv_i2, vv_i1)(__VA_ARGS__)

#define vvv_i1(Type, d_v, d_l, d_m, d_n)        vvv(Type) d_v (d_l, vv(Type)(d_m, v(Type)(d_n)))
#define vvv_i2(Type, d_v, d_l, d_m, d_n, v_ini) vvv(Type) d_v (d_l, vv(Type)(d_m, v(Type)(d_n, v_ini)))
#define vvv_i_overload2(a, b, c, d, e, f, g, ...) g
#define vvv_i(...) vvv_i_overload2(__VA_ARGS__, vvv_i2, vvv_i1)(__VA_ARGS__)

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

#define in_l1(type, d_l, d_n)\
    v(type) d_l( d_n );\
    rep(d_i, d_n) in(d_l[d_i]);
#define in_l2(type, d_l, d_m, d_n)\
    vv_i(type, d_l, d_m ,d_n);\
    rep(d_i, d_m){\
      rep(d_j, d_n) in(d_l[d_i][d_j]);\
    }
#define in_l_overload2(a, b, c, d, e, ...) e
#define in_l(...) in_l_overload2(__VA_ARGS__, in_l2, in_l1)(__VA_ARGS__)
    
#define in_l3(type, d_l, d_v)\
    v(type) d_l( d_v );\
    rep(d_i, d_v) in(d_l[d_i]);
    
#define in_vl(type_v, d_v, type_l, d_l)\
    in_v(type_v, d_v);\
    in_l1(type_l, d_l, d_v);

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
void print_v(string name, Type v){
  co name << ": ";
  fe(i, v)co i << ", ";
  br;
}
#define p_v(value) print_v(sn(value))

template<class Type>
void print_vv(string name, Type vv){
  co name << ": " en;
  co "{" en;
  fe(v, vv){
    co "  {";
    fe(i, v){
      co i << " ";
    }
    co "}" en;
  }
  co "}" en;
}
#define p_vv(value) print_vv(sn(value))

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
