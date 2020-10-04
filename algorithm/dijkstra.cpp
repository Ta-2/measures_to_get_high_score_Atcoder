/*
    ABC035_D
    https://atcoder.jp/contests/abc035/tasks/abc035_d

    -ダイクストラ法の実装-

*/

// #define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr long long inf  = (long long)1e18 + 1;

//最大値更新関数
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

//
struct edge{
    long long to;
    long long cost;
};

class graph{
private:
    long long V;
    vector<vector<edge>> G;

public:
    vector<long long> d;

//コンストラクタ
    graph(long long n){
        V = n;
        G.resize(V);
        d.resize(V);
        for(int i = 0; i < V; i++) d[i] = inf;
    }

    void add_edge(long long s, long long t, long long cost){
        edge e;
        e.to = t;
        e.cost = cost;
        G[s].push_back(e);
    }

    void dijkstra(long long s){
        for(int i = 0; i < V; i++){
            d[i] = inf;
        }

        d[s] = 0;

        priority_queue< pair< long long, long long>,
                        vector<pair<long long, long long>>,
                        greater<pair<long long, long long>>> que;

        que.push(pair<long long, long long>(0, s));

        while(!que.empty()){
            pair<long long, long long> p = que.top();
            que.pop();

            long long v = p.second;

            if(d[v] < p.first) continue;

            for(auto &e : G[v]){
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(pair<long long, long long>(d[e.to], e.to));
                }
            }

        }

    }

};


int main() {
    long long n, m, t;          //n:町(点)の数, m:道(辺)の数, t:時間
    cin >> n >> m >> t;
    long long ans = 0;          //所持金

    vector<long long> a(n);     //町ごとの所持金に加算される金額

    graph g1(n);                //順方向グラフ
    graph g2(n);                //逆方向グラフ

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(int i = 0; i < m; ++i){
        long long a, b, c;      //a番の町からb番の町へ移動するのにc分かかる
        cin >> a >> b >> c;

        g1.add_edge(a - 1, b - 1, c);
        g2.add_edge(b - 1, a - 1, c);
    }

    g1.dijkstra(0);
    g2.dijkstra(0);

    for(int i = 0; i < n; ++i){
        if(t < g1.d[i] + g2.d[i]) continue;

        long long money = a[i] * (t - g1.d[i] - g2.d[i]);
        chmax(ans, money);      //所持金の最大値の更新
    }

    cout << ans << endl;        //所持金の最大値(答え)の出力

return 0;
}