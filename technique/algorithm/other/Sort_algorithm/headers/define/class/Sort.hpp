/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    class Sort : public    SortBase    <std::vector<int>::iterator, std::vector<int>>,
                 protected MergeBase   <std::vector<int>::iterator, std::vector<int>>,
                 protected QuickBase   <std::vector<int>::iterator, std::vector<int>>,
                 protected Binary_Heap <int>
    {
    protected:
        void Insertion(RandomIter first, RandomIter last);
        void Heap_itr(RandomIter first, RandomIter last);
        void Shell(RandomIter first, RandomIter last);
        Container make_gap(RandomIter first, RandomIter last);  //シェルソートのギャップ列を求める
        void Shell(RandomIter first, RandomIter last, Container gap);
        inline void Distribute(int value, Container &vec);

    public:
        //コンストラクタ(n: 配列の要素の最大値)
        Sort(Container &v, int n){          //vは参照渡しにしないと全要素が0になってしまう
            initArray(v.begin(), v.end(), n);
        }

        //コンストラクタ(n: 配列の要素の最大値, m: 配列の要素の最小値)
        Sort(Container &v, int n, int m){
            initArray(v.begin(), v.end(), n, m);
        }

        //バブルソート(cnt:「〇回目…」を表示するかどうか, display_middle: ソートの途中経過を表示するかどうか, display_result: ソートの結果を表示するかどうか)
        void Bubble(RandomIter first, RandomIter last, bool cnt, bool display_middle, bool display_result);

        //選択ソート(cnt:「〇回目…」を表示するかどうか, display_middle: ソートの途中経過を表示するかどうか, display_result: ソートの結果を表示するかどうか)
        void Selection(RandomIter first, RandomIter last, bool cnt, bool display_middle, bool display_result);

        //挿入ソート(cnt:「〇回目…」を表示するかどうか, display_middle: ソートの途中経過を表示するかどうか, display_result: ソートの結果を表示するかどうか)
        void Insertion(RandomIter first, RandomIter last, bool cnt, bool display_middle, bool display_result);

        //マージソート(display_result: ソートの結果を表示するかどうか)
        void Merge(RandomIter first, RandomIter last, bool display_result);

        //クイックソート(display_result: ソートの結果を表示するかどうか)
        void Quick(RandomIter first, RandomIter last, bool display_result);

        //クイック-挿入ソート(display_result: ソートの結果を表示するかどうか)
        void Quick_Insertion(RandomIter first, RandomIter last, bool display_result);

        //ヒープソート(配列引数)(display_result: ソートの結果を表示するかどうか)
        void Heap(Container &vec7, bool display_result);

        //ヒープソート(イテレータ引数)(display_result: ソートの結果を表示するかどうか, greater: trueの時、降順にソートする)
        void Heap_itr(RandomIter first, RandomIter last, bool display_result, bool greater = false);

        //イントロソート(display_result: ソートの結果を表示するかどうか)
        void Intro(RandomIter first, RandomIter last, bool display_result);

        //シェルソート(display_result: ソートの結果を表示するかどうか)
        void Shell(RandomIter first, RandomIter last, bool display_result);

        //クイック-シェルソート(display_result: ソートの結果を表示するかどうか, arr_gap: ギャップ列を使用するかどうか)
        void Quick_Shell(RandomIter first, RandomIter last, bool display_result, bool arr_gap);

        //グラビティ―ソート(display_result: ソートの結果を表示するかどうか)
        Container Gravity(Container vec11);

    };

}

/*ソート関数の定義ヘッダ*/
#include "../function/Bubble.hpp"
#include "../function/Selection.hpp"
#include "../function/Insertion.hpp"
#include "../function/Merge.hpp"
#include "../function/Quick.hpp"
// #include "../function/Heap.hpp"    //これら2つのヘッダのうち
#include "../function/Heap_itr.hpp"   //「片方だけ」をインクルードすること。(#defineの競合を防ぐため)
#include "../function/Shell.hpp"
#include "../function/Gravity.hpp"
