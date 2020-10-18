#include <iostream>
#include <set>
using namespace std;

// using fastint = int;            //TLE
// using fastint = long;           //AC(AtCoderのみ)
using fastint = long long;      //AC(ローカル環境含め全環境で)

int main(){
    fastint n;
    cin >> n;

    set<fastint> ans;
    for(fastint d=1;d*d<=n;d++){
        if(n%d==0){
            ans.insert(d);
            ans.insert(n/d);
        }
    }

    for(auto x:ans)cout << x << endl;
}

/**
 * longは環境依存なのか…？
 * よくわからない。
 * とりあえず、オーバーフローとかを防ぐためにも
 * long longを使うのが確実だ。
 */

/*
 * 追記:
 * https://atcoder.jp/contests/apg4b/tasks/APG4b_y
 * の下、「環境依存の仕様」より
 *
 * long はAtCoder上で実行した場合 int64_t と同じ扱いになる
 * (つまり、AtCoder上ではlong と long long は同じ型)
 *
 * long は、次のようにOSの環境に依存する
 * 32ビットシステム -> long = int32_t
 * 64ビットシステム -> long = int64_t
*/