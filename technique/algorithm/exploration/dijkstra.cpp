/*
 *  ABC035_D
 *  https://atcoder.jp/contests/abc035/tasks/abc035_d
 *
 *  -ダイクストラ法の実装-
 *
*/

#include <vector>
#include <queue>
#include <numeric>

/*----------ここからDijkstra法の実装----------*/

template <typename Ty>
class Graph {
private:
    //無限大を表す定数
    const Ty INF = std::numeric_limits<Ty>::max();

    //辺の構造体
    struct Edge{
        Ty to;   //行き先の頂点
        Ty time; //toに行くのにかかる時間
    };

    //隣接リスト: G[i] = (j, time) -> 頂点iからjに時間timeで進める
    std::vector<std::vector<Edge>> G;

public:
    //最短時間の格納
    std::vector<Ty> d;

    //コンストラクタ
    Graph(Ty n): G(n), d(n, INF) {}

    //頂点sから頂点tへの時間timeの辺を張る
    void AddEdge(Ty _s, Ty _to, Ty _time) {
        Edge E;
        E.to = _to;
        E.time = _time;

        //グラフの_s番目に(_to, _time)をpush_backする
        G[_s].push_back(E);

        return;
    }

    //頂点sから各頂点への最短時間の探索(ダイクストラ法)
    void Dijkstra(Ty s) {
        d[s] = 0;               //頂点s(始点)までの最短時間を0に初期化する

        std::priority_queue
        <std::pair<Ty, Ty>,                 //要素の型
         std::vector<std::pair<Ty, Ty>>,    //要素のコンテナ
         std::greater<std::pair<Ty, Ty>>>   //要素の比較関数
        que;

        que.push(std::pair<Ty, Ty>(d[s], s));  //(time, to)の形をしているので注意

        while(!que.empty()){
            std::pair<Ty, Ty> p = que.top();
            que.pop();

            Ty v = p.second;

            for(auto &x : G[v]){
                if(d[x.to] > d[v] + x.time){    //(*1)参照

                    //頂点vから向かって頂点x.toに着く最短時間の更新
                    d[x.to] = d[v] + x.time;

                    //進んだ先の頂点x.toの情報をpushする
                    que.push(std::pair<Ty, Ty>(d[x.to], x.to));
                }
            }
        }

        return;
    }
};

/*----------Dijkstra法の実装ここまで----------*/

#include <iostream>

using ll = long long;

//最大値更新関数
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b)
{ return a < b && (a = b, true); }

int main() {
    //n:町(頂点)の数, m:道(辺)の数, t:上限時間
    ll n, m, t;
    std::cin >> n >> m >> t;

    //所持金
    ll ans = 0;

    //それぞれの町の所持金に加算される金額
    std::vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    Graph<ll> G1(n);            //順方向グラフのインスタンス化
    Graph<ll> G2(n);            //逆方向グラフのインスタンス化

    for(int i = 0; i < m; ++i) {
        ll a, b, c;             //a番の町からb番の町へ移動するのにc分かかる
        std::cin >> a >> b >> c;
        --a; --b;               //配列の添え字は0から始まるのでデクリメントする

        G1.AddEdge(a, b, c);    //順方向グラフの辺を張る
        G2.AddEdge(b, a, c);    //逆方向グラフの辺を張る
    }

    G1.Dijkstra(0);     //0から出発した時の最短時間の探索(順方向)
    G2.Dijkstra(0);     //0から出発した時の最短時間の探索(逆方向)

    for(int i = 0; i < n; ++i) {
        //(*2)参照
        if(t < G1.d[i] + G2.d[i]) continue;

        //(*3)参照
        ll money = a[i] * (t - (G1.d[i] + G2.d[i]));

        //所持金の最大値の更新
        chmax(ans, money);
    }

    //所持金の最大値(答え)の出力
    std::cout << ans << '\n';

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
