/**
 * ※このファイル単体では動作しません。Sort.hppにincludeして使用してください。
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Selection(RandomIter first, RandomIter last, bool cnt, bool display_middle, bool display_result){
        int count = 0;
        int COUNT = 0;

        if(last - first <= 1) return;

        // ソートを実施
        for(RandomIter fst = first; fst != last; ++fst){
            auto min = std::min_element(fst, last);

            if(fst == min){
                ++COUNT;
            }
            else{
                COUNT = 0;
            }

            std::iter_swap(fst, min);
            ++count;

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
        std::cout << '\n' << "Selection_Sort が " << count << " 回(実質 " << count - COUNT << " 回)の操作で完了しました。";
        std::cout << "(差分: " << COUNT << "回)" << '\n';

        return;
    }

}