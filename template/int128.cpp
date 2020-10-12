/**
 *  現状、シフト演算子のオーバーロードの挙動はほとんどさっぱりわからないが、
 *  とりあえず、128bit整数(符号付き、符号なし共に)の実装をした。
 *
 *  参考元サイト:
 *  https://kenkoooo.hatenablog.com/entry/2016/11/30/163533
 *
 *
 *  注:
 *  VSCodeでこのソースコードを開いたとき、恐らく「識別子 "__uint128_t" が定義されていません」
 *  と怒られるが、それは既定のワークスペースのintelliSenseModeがmsvc-x64になっているのが原因。
 *  (このままコンパイルしてもきちんと動作はするが、)
 *  もしこのエラー表示を直したいときは、
 *  c_cpp_properties.jsonのintelliSenseModeの部分をgcc-x64に書き換える必要がある。
 *
 *  すると今度は、「IntelliSense モード gcc-x64 は、コンパイラ パスと互換性がありません。」という
 *  エラーが表示されるので、c_cpp_properties.jsonのcompilerPathを書き換えてあげると良い。
 *  (mingw64のg++.exeは問題なかったが他は分からない。)
 *
*/

#include <iostream>
using namespace std;

//__uint128_t型の変数をcoutで出力できるようにする
std::ostream &operator<<(std::ostream &dest, __int128_t value){
    std::ostream::sentry s(dest);

    if(s){
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);     //配列の末尾のひとつ後ろを指すポインタ

        do{                                         //ナ
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
                                                    //ン
        }while(tmp != 0);

        if(value < 0){
            --d;                                    //ダ
            *d = '-';
        }

        int len = std::end(buffer) - d;             //コ
        if(dest.rdbuf()->sputn(d, len) != len){
            dest.setstate(std::ios_base::badbit);
        }
    }                                               //レ

    return dest;
}

//__uint128_t型の変数をcoutで出力できるようにする(以下、__int128_t型と構造は同じ)
std::ostream &operator<<(std::ostream &dest, __uint128_t value_u){
    std::ostream::sentry s(dest);

    if(s){
        __uint128_t tmp = value_u < 0 ? -value_u : value_u;
        char buffer[128];
        char *d = std::end(buffer);

        do{
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;

        }while(tmp != 0);

        if(value_u < 0){
            --d;
            *d = '-';
        }

        int len = std::end(buffer) - d;
        if(dest.rdbuf()->sputn(d, len) != len){
            dest.setstate(std::ios_base::badbit);
        }
    }

    return dest;
}

//string -> int128 変換関数(戻り値の型を必要に応じて変更すれば、かなり実用性の高い関数だと思う)
__uint128_t Parse(string &s){
    __uint128_t ret = 0;

    bool minus = false;             //入力した文字列が負数かどうかを格納
    if(s[0] == '-') minus = true;   //一文字目が"-"の時、フラグを立てる

    for(int i = 0; i < (int)s.length(); ++i){
        if('0' <= s[i] && s[i] <= '9'){     //文字列が0~9までの数のときのみ処理(整数のみ「抽出」するような挙動をする)
            ret = 10 * ret + s[i] - '0';    //(10 * ret) + (s[i] - '0')と置くと見やすい
        }
    }

    if(minus) ret *= -1;            //もし、文字列の先頭に"-"があれば、マイナスを掛ける

    return ret;
}

int main(){

    string sd = "170141183460469231731687303715884105727";   // 170141183460469231731687303715884105727  = 2^127 - 1 (__int128_t  : maximum)
    string nd = "-170141183460469231731687303715884105728";  // -170141183460469231731687303715884105728 = -2^127    (__int128_t  : minimum)
    string ud = "340282366920938463463374607431768211455";   // 340282366920938463463374607431768211455  = 2^128 - 1 (__uint128_t : maximum)

    cout << "---string---" << endl;
    cout << sd << endl;             //入力した数の確認
    cout << nd << endl;             //入力した数の確認
    cout << ud << endl;             //入力した数の確認
    cout << endl;

    __int128_t  sx = Parse(sd);     //数値に変換
    __int128_t  nx = Parse(nd);     //数値に変換
    __uint128_t ux = Parse(ud);     //数値に変換

    cout << "---integer---" << endl;
    cout << sx << endl;
    cout << nx << endl;
    cout << ux << endl;
    cout << endl;

    cout << "input(string)  = ";
    string hoge; cin >> hoge;
    __int128_t huga = Parse(hoge);
    cout << "output(int128) = " << huga << endl;

return 0;
}