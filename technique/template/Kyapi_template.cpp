#pragma GCC optimize("O3")
// #define _GLIBCXX_DEBUG

/*----------------headers-----------------*/
#include <algorithm>    //utility
#include <bitset>       //string
#include <cassert>
#include <cmath>
#include <iomanip>      //locale
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>        //vector(, deque)
#include <set>
#include <stack>        //deque
using namespace std;

#include <chrono>
using namespace std::chrono;

/*-----------------macros-----------------*/

//input, output, debug======================
#define endl '\n'

#define fastio                              \
std::ios::sync_with_stdio(false);           \
std::cin.tie(nullptr);                      \
std::cout.tie(nullptr)

#define fcout(a)                            \
cout << fixed << setprecision((int)(a))

#define scout(a)                            \
cout << setprecision((int)(a))

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

//type alias================================
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using vi  = vector<int>;
using vl  = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

//const number==============================
constexpr int INF   = (int)1e9 + 1;
constexpr ll  INFll = (ll)1e18 + 1;
constexpr int MOD1  = 1000000007;
constexpr int MOD2  = 998244353;
constexpr ld  PI    = 3.141592653589793L;
constexpr ld  EPS   = 1e-14;

vi
dx  = {1, 0, -1, 0},
dy  = {0, 1, 0, -1},
dx2 = {1, 1, 0, -1, -1, -1, 0, 1},
dy2 = {0, 1, 1, 1, 0, -1, -1, -1};

//member alias==============================
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

//functions=================================
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b)
{ return a < b && (a = b, true); }

template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b)
{ return a > b && (a = b, true); }


/*--------------macro is end--------------*/
//****************************************//

/*-----------------global-----------------*/



/*---------------additional---------------*/



/*-----------------solve------------------*/

void Main() {
fastio;



    return;
}

/*-----------------main-------------------*/

int main() {

    auto _Start_ = system_clock::now();
    Main();
    auto _End_ = system_clock::now();

    auto _Time_ = duration_cast<milliseconds>(_End_ - _Start_).count();
    cerr << _Time_ << "ms" << endl;

    return 0;
}