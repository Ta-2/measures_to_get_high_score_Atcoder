#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

//ビットの制御についてフィルターを考える
int main(){
  int n = 3;

  //ビットフィールドを宣言
  bit_field filter = {0};
  //3bit目を1にする
  filter.bits[2].bit = 1;
  printf("%d\n", sizeof(a));

  //総当たりを行う
  for(int bit = 0; bit < (1<<n); bit++){
    vector<int> S;
    //if((bit & filter.value) == filter.value)continue;
    //bit = bit | filter.value;
    for(int i = 0; i < n; ++i){
      if(bit & (1<<i)){
        S.push_back(i);
      }
    }

    cout << bit << ": {";
    for(int i = 0; i < (int)S.size(); ++i){
      cout << S[i] << " ";
    }
    cout << "}" << endl;
  }

  return 0;
}
