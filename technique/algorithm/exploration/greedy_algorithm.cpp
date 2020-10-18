/*
 *  キーエンスプログラミングコンテスト2020_B
 *  https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
 *
 *  -貪欲法の実装-
 *
*/

//#define _GLIBCXX_DEBUG    <- debug
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;          //ロボットの数
    cin >> n;

    vector<pair<int, int>> p;   //それぞれのロボットの腕の可動域の両端を格納
    p.reserve(n);

    for(int i = 0; i < n; ++i){
        int x, l;   //x: ロボットの座標, l: ロボットの腕の長さ
        cin >> x >> l;

        p.push_back(make_pair(x + l, x - l));   //(右端の座標, 左端の座標)
    }

    sort(p.begin(), p.end());   //vector<pair>のsortは、firstに注目して行う

    int res = 0;                //取り除くロボットの数
    int x = p[0].first;         //残すロボットの右端の座標

    for(int i = 1; i < n; ++i){
        if(x > p[i].second){    //残すロボットの右端の座標が次のロボットの左端の座標より大きいとき、
            ++res;              //そのロボットを取り除く
        }
        else{
            x = p[i].first;     //取り除かないならば、そのロボットの右端の座標に更新する
        }
    }

    cout << n - res << endl;

    return 0;
}

/*
ポイント:   現在の状態とその次の状態に『だけ』着目して最適化するのが、貪欲法
            それだけでなく、全体の状態にも着目して最適化するのが、動的計画法
            最適化そっちのけで愚直に全パターンを列挙するのが、全探索

            (これらの表現が合っているかどうかは分からない)

*/