#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(){
  const int n = 3;  //要素数
  const int lim = 3;  //1要素がとれる種類
  int search_v = 1; //1要素を表すのに必要なbit数を計算
  while( (1<<(search_v)) < lim )search_v++;
  const int v = search_v;  //1要素の持つbit数
  const int r = (1<<v) - lim; //探索が必要ない部分の階数

  cout << "v: " << v << ", r: " << r << endl;
  int mask = 0; //マスクを宣言
  int count = 0; //カウント用変数を用意
  for(int i = 0; i < v; i++)mask += (1<<i); //マスクを生成
  cout << "mask: " << bitset<n>(mask) << endl;

  for(int bit = 0; bit < 1<<v*n; bit++){  //全走破するためのbit
    if(count == lim){ //bitで探索する必要の無い部分をスキップする
      count = 0;
      bit += r;
    }
    cout << "bit: " << bitset<6>(bit) << endl;
    vector<int> S; //全ての組み合わせを格納する
    for(int i = 0; i < n; i++){
      int check_bit = bit>>(i*v); //検知する部分までシフトする
      for(int bit_v = 0; bit_v < lim; bit_v++){
        if((check_bit & mask) == bit_v){
          S.push_back(bit_v);
          cout << "bit_v: " << bitset<2>(bit_v) << ", check_bit; " << bitset<2>(check_bit) << endl;
        }
      }
    }

    cout << bit << ": {";
    for(int i = 0; i < (int)S.size(); ++i){
      cout << S[i] << " ";
    }
    cout << "}" << endl;

    count++;
  }

  return 0;
}
