#include <iostream>
#include <vector>
using namespace std;

//1bitを再現する構造体
typedef struct bit{
  unsigned int bit: 1;
} bit;
//32bitを再現する構造体
typedef union bit_field{
  int value;
  bit bits[32];
} bit_field;

//ビットの制御についてフィルターを考える
int main(){
  int n = 3;

  //ビットフィールドを宣言
  bit_field filter = {0};

  for(int bit = 0; bit < (1<<n); bit++){
    vector<int> S;
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
