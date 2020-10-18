#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

//ビットの制御についてフィルターを考える
int main(){
    constexpr int n = 6;                //扱うビット数を定数で定義
    const string s = "000001";          //フィルターとなるbit列をstringで定義
    bitset <n> filter(s);               //フィルターをbitsetで生成


#ifdef __LOCAL__
    cerr << "n -> " << n << endl;       //debug
    cerr << "filter -> " << s << endl;  //debug
#endif


//総当たりを行う
    for(int bit = 0; bit < (1 << n); ++bit){
        vector<int> S;                  //全ての組み合わせをここでまとめる
        S.reserve(n);                   //Sにpush_backする時に、無駄なメモリの確保を防ぐ(今回はほぼ無意味)
        bitset<n> now_bit(bit);         //現在のbitをbitsetに変換

    //ここで、filterとbitに立っているフラグがひとつでも重複している場合、処理をとばす。
        if((now_bit & filter).count()) continue;

    //(フィルターと)重複していない組み合わせにフィルターを掛ける
        now_bit |= filter;

    //組み合わせをSにpush_backしていく
        for(int i = 0; i < n; ++i){
            bitset<n> check(1);         //比較用に1をbitsetを用意

            if((now_bit & (check << i)).count()){
                S.push_back(i);         //要素をpush_backしていく
            }
        }

    //(フィルターを経た)全ての組み合わせを表示
        cout << bit << "(番目): { ";
        for(int i = 0; i < (int)S.size(); ++i) cout << S[i] << " ";
        cout << "}" << endl;
    }

  return 0;
}