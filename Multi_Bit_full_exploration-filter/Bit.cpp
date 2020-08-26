#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(){
  const int n = 4;  //要素数
  const int lim = 5;  //1要素がとれる種類
  int search_v = 1; //1要素を表すのに必要なbit数を計算
  while( (1<<(search_v)) < lim )search_v++;
  const unsigned int v = search_v;  //1要素の持つbit数
  const unsigned int r = (1<<v) - lim; //探索が必要ない部分の階数

  cout << "v: " << v << ", r: " << r << endl;
  int mask = 0; //マスクを宣言
  int count[n] = {}; //カウント用変数を用意
  for(unsigned int i = 0; i < v; i++)mask += (1<<i); //マスクを生成
  cout << "mask: " << bitset<n>(mask) << endl;

  for(unsigned int bit = 0; bit < (unsigned)1<<v*n; bit++){  //全走破するためのbit
    for(int i = 0; i < n; i++){
      if(count[i] == lim){ //bitで探索する必要の無い部分をスキップする
        count[i] = 0;
        if(i != n-1)count[i+1]++;
        bit += r<<(i*v);
      }
    }
    cout << "bit: " << bitset<12>(bit) << endl;

    vector<int> S; //全ての組み合わせを格納する
    for(int i = 0; i < n; i++){
      int check_bit = bit>>(i*v); //検知する部分までシフトする
      for(int bit_v = 0; bit_v < lim; bit_v++){
        if((check_bit & mask) == bit_v){
          S.push_back(bit_v);
          cout << "bit_v: " << bitset<3>(bit_v) << ", check_bit; " << bitset<3>(check_bit) << endl;
        }
      }
    }

    cout << bit << ": {";
    for(int i = 0; i < (int)S.size(); ++i){
      cout << S[i] << " ";
    }
    cout << "}" << endl;

    count[0]++;
  }

  return 0;
}
