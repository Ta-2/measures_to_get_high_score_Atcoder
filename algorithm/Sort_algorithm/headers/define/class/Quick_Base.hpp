/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    class QuickBase{
    protected:
        void quick_sort(RandomIter first, RandomIter last){

            if (last - first <= 1) return;

            auto i = first, j = last - 1;

            for (auto pivot = first; true; ++i, --j){
                while (*i < *pivot) ++i;

                while (*pivot < *j) --j;

                if (i >= j) break;

                std::iter_swap(i, j);
            }

            quick_sort(first, i);

            quick_sort(j + 1, last);

                return;
        }

        void partial_quick_sort(RandomIter first, RandomIter last){

            if (last - first <= 32) return;     //32�܂���64���œK

            auto i = first, j = last - 1;

            for (auto pivot = first; true; ++i, --j){
                while (*i < *pivot) ++i;

                while (*pivot < *j) --j;

                if (i >= j) break;

                std::iter_swap(i, j);
            }

            partial_quick_sort(first, i);

            partial_quick_sort(j + 1, last);

                return;
        }

    };

}