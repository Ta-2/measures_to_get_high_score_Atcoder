/**
 * ※このファイル単体では動作しません。Sort.hppにincludeして使用してください。
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Bubble(RandomIter first, RandomIter last, bool cnt, bool display_middle, bool display_result){
        int count = 0;

        if(last - first <= 1) return;

        // ソートを実施
        for(RandomIter i = first; i != last; ++i){
            bool complete = true;   //要素の入れ替えがあったらfalseになる

            for(RandomIter j = last - 1; j != i; --j){
                if(iter_sorting_swap(j, j - 1)){
                    complete = false;
                }
            }

            ++count;

            if(complete){
                break;     //一度も要素の入れ替えがない(ソートが完了した)時、処理を抜ける
            }

            if(display_middle){
                showArray(first, last);

                if(cnt){
                    std::cout << "(" << count << "回目)";
                }
                std::cout << '\n';
            }
        }

        if(display_result){
            std::cout << '\n';
            showArray(first, last);
        }
        std::cout << '\n' << "Bubble_Sort が " << count - 1 << " 回の操作で完了しました。" << '\n';

        return;
    }

}