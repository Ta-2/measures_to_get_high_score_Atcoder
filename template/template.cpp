#pragma GCC optimize("O3")
//  GCCの最適化オプションの指定をしている。atcoderのデフォルトは-O2。

#define _GLIBCXX_DEBUG
//  #define _GLIBCXX_DEBUGは、operator[]に対し範囲外チェックを有効にする。
//  が、at.()よりも範囲外チェックの動作は遅いのでデバッグ以外はコメントアウトすべき。

using namespace std;

#include <algorithm>    //utility
#include <bitset>       //string
#include <cassert>
#include <cmath>
#include <iomanip>      //locale
#include <iostream>
#include <list>
#include <map>
#include <queue>        //vector(, deque)
#include <set>
#include <stack>        //deque
//  各ヘッダ横のコメントアウトは、ヘッダ内でincludeされているヘッダ。
//  ただ単に、行数の削減がしたいだけ。

/*-----------------macros-----------------*/

//input, output, debug======================
#define endl '\n'
//  std::endlは、改行以外の処理も含まれていて遅いので高速な\nに置換している。

#define fastio                              \
std::ios::sync_with_stdio(false);           \
std::cin.tie(nullptr);                      \
std::cout.tie(nullptr)
//  fastioマクロは、c++標準入出力の高速化をしている。
//  こうすることで、scanf,printf並みに速くなる。(なお実感はない模様)

#define fcout(a)                            \
cout << fixed << setprecision((int)(a))
//  fcoutの引数に入れた数だけの精度の小数を出力してくれる。
//  ex.) fcout(10) << var << endl; <- 小数点以下10桁まで変数varの値を出力。

#define dcoutvar(x)                         \
cerr << "-----error_output-----" << endl;   \
cerr << "varname::" << #x << " -> ";        \
cerr << x << endl;                          \
cerr << "----------------------" << endl

#define dcoutarr(v, n)                      \
cerr << "-----error_output-----" << endl;   \
cerr << "arrname::" << #v << endl;          \
for(int i = 0; i < (n); ++i){               \
    cerr << v[i] << " ";                    \
}                                           \
cerr << endl;                               \
cerr << "----------------------" << endl;

#define dcoutvec(v)                         \
cerr << "-----error_output-----" << endl;   \
cerr << "vecname::" << #v << endl;          \
for(auto &x : (v)){                         \
    cerr << x << " ";                       \
}                                           \
cerr << endl;                               \
cerr << "----------------------" << endl;

#define dcoutvec2(v)                        \
cerr << "-----error_output-----" << endl;   \
cerr << "vecname_2::" << #v << endl;        \
for(auto &x : (v)){                         \
    for(auto &y : (x)){                     \
        cerr << y << " ";                   \
    }                                       \
cerr << endl;                               \
}                                           \
cerr << "----------------------" << endl;
//  "dcout...(var)は、「変数名」と「変数の値」を標準エラー出力に出力する。
//  (配列のデバッグに特に便利だけどちょっと煩雑になる。)

//typedef===================================
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using Vi  = vector<int>;
using Vl  = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

//const number==============================
constexpr int INF   = (int)1e9 + 1;
constexpr ll  INFll = (ll)1e18 + 1;
constexpr int MOD1  = 1000000007;
constexpr int MOD2  = 998244353;
constexpr ld  PI    = 3.141592653589793L;
//  #define定数で書いて事故ると嫌なので
//  よく使う定数はコンパイル時定数としている。

//member====================================
#define pb push_back
#define eb emplace_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

//others====================================
#define sz(x)                               \
(int) x.size()

#define all(x)                              \
(x).begin(), (x).end()

#define rall(x)                             \
(x).rbegin(), (x).rend()

#define rep(i, n)                           \
for(int i = 0; (i) < (n); ++(i))

#define reps(i, n)                          \
for(int i = 1; (i) <= (n); ++(i))

#define rrep(i, n)                          \
for(int i = n - 1; (i) >= 0 ; --(i))

#define repbit(bit, n)                      \
for(int bit = 0; (bit) < (1 << (n)); ++(bit))

#define ifbit(bit, i)                       \
if((bit) & (1 << (i)))

#define CtoI(c)                             \
int((c)) - int('0')

#define ItoC(c)                             \
char((c) + '0')
//  CtoI, ItoCは、いちいちクオテーション打ちたくないので定義した。

//functions=================================
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b)
{ return a < b && (a = b, true); }

template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b)
{ return a > b && (a = b, true); }
//  chmax, chmin関数は、戻り値がboolなので、「何回数が更新されたか」の処理をシンプルにかけてめちゃ便利。
//  return以降の処理は、「条件式を満たすならば、数を更新してtrueを返す」という意味。
//  コンマ演算子はまだよく分かってない。

Vi  dx = {1, 0, -1, 0},
    dy = {0, 1, 0, -1};

Vi  dx2 = { 1,1,0,-1,-1,-1,0,1 },
    dy2 = { 0,1,1,1,0,-1,-1,-1 };

/*---------------additional---------------*/



/*-----------------main-------------------*/

int main() {
fastio;



return 0;
}