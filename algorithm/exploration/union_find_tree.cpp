/*
 *  ARC032_B
 *  https://atcoder.jp/contests/arc032/tasks/arc032_2
 *
 *  -union_find_treeの実装-
 *
*/

//#define _GLIBCXX_DEBUG    <- debug
#include <iostream>
#include <vector>
using namespace std;


/*----------ここからunion_find_treeの実装----------*/

class UnionFind{
public:
    std::vector<int> par;       //par[i]  -> iの親の番号
    std::vector<int> size;      //size[i] -> 『根』iに繋がる要素の個数(ランク)
    int num;                    //コンストラクタ引数の格納

    //コンストラクタ
    UnionFind(int _n) : par(_n), size(_n, 0), num(_n){
        //全ての要素が根(par[i] = iとなるi)であるとして初期化
        for(int i = 0; i < _n; i++) par[i] = i;
    }

    //xが属する木の根を取得
    int root(int x);

    //xが属する木のランクを取得
    int rank(int x);

    //「xが属する木」と「yが属する木」を併合
    void unite(int x, int y);

    //x, yが属する木が同じかを判定
    bool same(int x, int y);

    //独立した木の個数を取得
    int count();

};

int UnionFind::root(int x){             //再帰探索
    if (par[x] == x) return x;
    return par[x] = root(par[x]);       //ここで経路の短縮も行う
}

int UnionFind::rank(int x){
    return size[root(x)];
}

void UnionFind::unite(int x, int y){
    if (root(x) == root(y)) return;

    if(rank(x) < rank(y)){
        par[root(x)] = root(y);         //ランクが高い方の木に併合
    }
    else{
        par[root(y)] = root(x);         //ランクが高い方の木に併合

        if(rank(x) == rank(y)){
            ++size[root(x)];            //ランクが同じときは併合する木のランクをインクリメント
        }
    }

    return;
}

bool UnionFind::same(int x, int y){
    return root(x) == root(y);
}

int UnionFind::count(){
    int ret = 0;
    for(int i = 0; i < num; ++i){
        if(par[i] == i) ++ret;          //「木が独立している⇔根が違う値を持つ」なので、根の個数を数えている
    }

    return ret;
}

/*----------union_find_treeの実装ここまで----------*/


int main() {
    int n, m;                           //n: 交差点の個数, m: 道路の個数
    cin >> n >> m;

    UnionFind tree(n);                  //UnionFindクラスのインスタンス化

    vector<int> a(m), b(m);             //道路の両端の交差点
    for(int i = 0; i < m; ++i){
        cin >> a[i] >> b[i];
        --a[i]; --b[i];                 //配列の引数として扱うためデクリメント

        tree.unite(a[i], b[i]);         //UnionFind木の併合
    }

    int ans = tree.count() - 1;         //(*1)参照

    cout << ans << endl;

return 0;
}

/*
注:
(*1)    求めるものは、『どの交差点にも行けるようにするための最小の道路追加数』
        そのためにまず、『どの交差点が道路を介して繋がっているか』を
        UnionFindによって調べた(繋がっている交差点は同一の木の要素となる)
        そして、『どの交差点にも道路を介して行ける』ということは、
        『全ての交差点が、同一の木の要素に含まれる』ことと同値である
        ゆえに、現在の独立した木の個数が分かれば、その個数から1引いたものが
        道路追加数となる
*/