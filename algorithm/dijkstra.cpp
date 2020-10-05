/*
 *  ABC035_D
 *  https://atcoder.jp/contests/abc035/tasks/abc035_d
 *
 *  -ダイクストラ法の実装-
 *
*/

//#define _GLIBCXX_DEBUG   <- debug
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//無限大を表す定数
constexpr long long inf  = (long long)1e18 + 1;

//最大値更新関数
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }


/*----------ここからDijkstra法の実装----------*/

//辺の構造体
struct edge{
    long long to;   //行き先の頂点
    long long time; //toに行くのにかかる時間
};

class graph{
private:
    vector<vector<edge>> G; //グラフ配列
                            //G[i] = (j, time) -> 頂点iからjに時間timeで進める

public:
    vector<long long> d;    //最短時間の格納

//コンストラクタ
    graph(long long n);

//頂点sから頂点tへの時間timeの辺を張る
    void add_edge(long long _s, long long _to, long long _time);

//頂点sから各頂点への最短時間の探索(ダイクストラ法)
    void dijkstra(long long s);
};

graph::graph(long long n){
    G.resize(n);
    d.resize(n);
    for(int i = 0; i < n; i++){
        d[i] = inf;         //最短時間を無限大で初期化
    }
}

void graph::add_edge(long long _s, long long _to, long long _time){
    edge E;
    E.to = _to;
    E.time = _time;
    G[_s].push_back(E);     //グラフの_s番目に(_to, _time)をpush_backする

    return;
}

void graph::dijkstra(long long s){
    d[s] = 0;               //頂点s(始点)までの最短時間を0に初期化する

    priority_queue
    < pair<long long, long long>,           //要素の型
      vector<pair<long long, long long>>,   //要素のコンテナ
      greater<pair<long long, long long>> > //要素の比較関数
      que;

    que.push(pair<long long, long long>(d[s], s));  //(time, to)の形をしているので注意

    while(!que.empty()){
        pair<long long, long long> p = que.top();
        que.pop();

        long long v = p.second;

        for(auto &x : G[v]){
            if(d[x.to] > d[v] + x.time){    //(*1)参照

                //頂点vから向かって頂点x.toに着く最短時間の更新
                d[x.to] = d[v] + x.time;

                //進んだ先の頂点x.toの情報をpushする
                que.push(pair<long long, long long>(d[x.to], x.to));
            }
        }
    }

    return;
}

/*----------Dijkstra法の実装ここまで----------*/


int main() {
    long long n, m, t;          //n:町(頂点)の数, m:道(辺)の数, t:上限時間
    cin >> n >> m >> t;
    long long ans = 0;          //所持金

    vector<long long> a(n);     //それぞれの町の所持金に加算される金額
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    graph G1(n);                //順方向グラフのインスタンス化
    graph G2(n);                //逆方向グラフのインスタンス化

    for(int i = 0; i < m; ++i){
        long long a, b, c;      //a番の町からb番の町へ移動するのにc分かかる
        cin >> a >> b >> c;
        --a; --b;               //配列の添え字は0から始まるのでデクリメントする

        G1.add_edge(a, b, c);   //順方向グラフの辺を張る
        G2.add_edge(b, a, c);   //逆方向グラフの辺を張る
    }

    G1.dijkstra(0);             //0から出発した時の最短時間の探索(順方向)
    G2.dijkstra(0);             //0から出発した時の最短時間の探索(逆方向)

    for(int i = 0; i < n; ++i){
        if(t < G1.d[i] + G2.d[i]) continue; //(*2)参照

        long long money = a[i] * (t - (G1.d[i] + G2.d[i])); //(*3)参照

        chmax(ans, money);      //所持金の最大値の更新
    }

    cout << ans << '\n';        //所持金の最大値(答え)の出力

return 0;
}

/*
注:

(*1)    if(d[x.to] > d[v] + x.time) は、条件式の
        左辺は、「頂点x.toまでに必要な最短時間」、
        右辺は、「今いる頂点vまでの最短時間に、頂点x.toに進むための時間を足したもの」
        であり、この条件を満たさない時、頂点v -> x.toのルートは通らない(continue)
        という意味を持つ

(*2)    (G1.d[i] + G2.d[i]) は、始点から頂点iまでの往復の時間の合計を表す
        寄り道せずに往復しただけのコストが上限時間tを超えているときは探索しない、
        という意味を持つ

(*3)    まずこの問題で一番押さえておくべき事は、『滞在すべき町はただ1つだ』ということ。
        複数の町に滞在するよりも、時間制限(ここではt)に間に合う町のうち、
        最も加算される金額の大きい町に最大限滞在した方がいい。

        そうなれば、求める所持金の最大値は、
        『往復t以内の時間で行ける町(*2参照)のうち、最も単位時間当たりの加算額(a[i])の大きい町』
        に、『往復移動時間以外の残りの時間(t - (G1.d[i] + G2.d[i]))』を掛けた値になる

*/