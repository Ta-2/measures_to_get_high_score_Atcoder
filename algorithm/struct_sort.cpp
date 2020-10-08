/**
 * ABC_128_B
 * https://atcoder.jp/contests/abc128/tasks/abc128_b
 *
 * -構造体・クラスのソート-
 *
 * C++のSTLでは、オブジェクトの比較には暗黙的にoperator<が使用されている。
 * 構造体はそのままでは比較できないので演算子のオーバーロードをする。(比較関数の実装でも良い)
 *
 * 演算子のオーバーロードをすれば、maxやlower_boundも同様に使用できるようになる。
 *
*/

#include <iostream>
#include <algorithm>
using namespace std;

class restaurant{
public:
	string city;
	int score;
	int num;

	inline bool operator < (const restaurant &other) const{
		return  (this->city != other.city) ?    //cityが違うかどうか判定
                (this->city  < other.city) :    //違う時、cityを昇順に
                (this->score > other.score);    //同じ時、scoreを降順に
	}
};

int main(){
	int n; cin >> n;
    restaurant res[105];

	for(int i = 1; i <= n; ++i){
        string s; int p;
		cin >> s >> p;
        res[i].city = s;
        res[i].score = p;
		res[i].num = i;
	}

	sort(res + 1, res + n + 1);     //resは、配列の先頭のイテレータ(正確にはポインタ)を指す

	for(int i = 1; i <= n; ++i){
        cout << res[i].num << endl;
    }

return 0;
}