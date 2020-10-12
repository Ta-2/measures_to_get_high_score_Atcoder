/****************ヘッダ群****************/

/*c++標準ライブラリヘッダ*/
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

/*ソート関数の基礎関数・クラスのヘッダ*/
#include "headers/define/class/Sort_Base.hpp"
#include "headers/define/class/Merge_Base.hpp"
#include "headers/define/class/Quick_Base.hpp"
#include "headers/define/class/Binary_heap.hpp"

/*ソート関数全体を管理するクラスのヘッダ*/
#include "headers/define/class/Sort.hpp"

#define CMD_RUN 0   //cmd上で実行したい時は1にする

/****************メイン関数****************/
int main(){

#if CMD_RUN
printf("Start sort to press any key...");
getchar();
#endif

/*ソートを行う配列の大きさと要素の取りうる範囲をあらかじめ指定*/
    constexpr int n = (int)1e3;
    constexpr int MAX = 32;
    constexpr int MIN = 1;  //Gravity_Sort使用時は、MINを必ず1以上にすること。

    std::cout << "Sortする配列の要素数は " << n << " です。\n";
    std::cout << "Sortする配列の最大値は " << MAX << " です。\n";
    std::cout << "Sortする配列の最小値は " << MIN << " です。\n\n";

    std::cout << "Sortする配列の生成をしています...\n";

/*ソートを行うデータの格納配列*/
    std::vector<int> vec0(n);        //STL_sort() ... 標準ソート


/*Sortオブジェクトの生成(vec0配列を、ランダムな要素で初期化)*/
    kya::Sort<std::vector<int>::iterator, std::vector<int>>
    Sort(vec0, MAX, MIN);


/*以降、初期化済み配列のコピー処理*/
    std::vector<int> rev_vec0 = vec0;   //reverse_STL_sort()
    std::vector<int> vec00 = vec0;      //STL_stable_sort()
    std::vector<int> vec1  = vec0;      //Bubble_Sort
    std::vector<int> vec2  = vec0;      //Selection_Sort
    std::vector<int> vec3  = vec0;      //Insertion_Sort
    std::vector<int> vec4  = vec0;      //Merge_Sort
    std::vector<int> vec5  = vec0;      //Quick_Sort
    std::vector<int> vec6  = vec0;      //Quick_Insertion_Sort
    std::vector<int> vec7  = vec0;      //Heap_Sort
    std::vector<int> vec8  = vec0;      //Intro_Sort
    std::vector<int> vec9  = vec0;      //Shell_Sort
    std::vector<int> vec10 = vec0;      //Quick_Shell_Sort
    std::vector<int> vec11 = vec0;      //Gravity_Sort
    std::vector<int> Vec11;             //Gravity_Sort(result)

    std::cout << "Sortする配列の生成が完了しました。\n\n";


/*ソート関数の実行と結果の表示(使わないソートのヘッダはコメントアウトする)*/
    #include "headers/output/STL_stable.hpp"
    #include "headers/output/Bubble.hpp"
    #include "headers/output/Selection.hpp"
    #include "headers/output/Insertion.hpp"
    #include "headers/output/Merge.hpp"
    #include "headers/output/Quick.hpp"
    #include "headers/output/Quick_Insertion.hpp"
    #include "headers/output/Heap.hpp"
    #include "headers/output/Intro.hpp"
    #include "headers/output/Shell.hpp"
    #include "headers/output/Quick_Shell.hpp"
    #include "headers/output/Gravity.hpp"

/*このヘッダは基本的にコメントアウトしないこと*/
    #include "headers/output/STL.hpp"


/*各ソートの結果が標準ソートの結果に一致するかどうかの確認(上でコメントアウトしたソートに対応する条件式はコメントアウトする)*/
    if(
        vec0 == vec00 &&    //STL_stable_sort()
        vec0 == vec1  &&    //Bubble
        vec0 == vec2  &&    //Selection
        vec0 == vec3  &&    //Insertion
        vec0 == vec4  &&    //Merge
        vec0 == vec5  &&    //Quick
        vec0 == vec6  &&    //Quick_Insertion
        vec0 == vec7  &&    //Heap
        vec0 == vec8  &&    //Intro
        vec0 == vec9  &&    //Shell
        vec0 == vec10 &&    //Quick_Shell
        rev_vec0 == Vec11 &&    //Gravity
        true
    ){ std::cout << "各Sortによる出力はすべて基準に一致しています。\n"; }
    else{ std::cout << "各Sortによる出力のどれかが基準に一致しません。\n"; }

#if CMD_RUN
printf("End exe to press any key...");
getchar();
#endif

    return 0;
}