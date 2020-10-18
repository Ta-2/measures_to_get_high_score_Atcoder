#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

//ビットの制御についてフィルターを考える
int main(){
  const int n = 3;  //扱うビット数を定数で定義
  bitset <n> filter("101"); //フィルターをbitsetで生成する

  //総当たりを行う
  for(int bit = 0; bit < (1<<n); bit++){
    vector<int> S;  //全ての組み合わせをここでまとめる
    bitset<n> now_bit(bit); //現在のbitをbitsetに変換する
    //ここで既にフィルターにある要素がひとつでも入っている場合、次の処理にまわすことで
    //重複を回避している
    if((now_bit & filter).count() > 0)continue;
    now_bit |= filter;  //重複していない組み合わせにフィルターを掛ける
    for(int i = 0; i < n; ++i){ //組み合わせをSにpush_backしていく
      bitset<n> check(1); //比較用に1をbitsetを用意する
      if((now_bit & (check<<i)).count()){
        S.push_back(i);  //要素をpush_backしていく
      }
    }

    //組み合わせを表示していく
    cout << bit << ": {";
    for(int i = 0; i < (int)S.size(); ++i){
      cout << S[i] << " ";
    }
    cout << "}" << endl;
  }

  return 0;
}
