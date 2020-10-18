/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.hpp��include���Ďg�p���Ă��������B
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Insertion(RandomIter first, RandomIter last, bool cnt, bool display_middle, bool display_result){
        int count = 0;

        if(last - first <= 1) return;
        if(*first > *(first + 1)) iter_swap(first, first + 1);

        // �\�[�g�����{
        for(RandomIter i = first + 1; i != last; ++i){
            for(RandomIter j = i; j != first; --j){
                if(!iter_sorting_swap(j, j - 1)){
                    break;
                }
            }

            ++count;

            if(display_middle){
                showArray(first, last);

                if(cnt){
                    std::cout << "(" << count << "���)";
                }
                std::cout << '\n';
            }
        }

        if(display_result){
            std::cout << '\n';
            showArray(first, last);
        }
        std::cout << '\n' << "Insertion_Sort �� " << count << " ��̑���Ŋ������܂����B" << '\n';

        return;
    }

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Insertion(RandomIter first, RandomIter last){
        if(last - first <= 1) return;
        iter_sorting_swap(first, first + 1);

        // �\�[�g�����{
        for(auto i = first + 1; i != last; ++i){
            for(auto j = i; j != first; --j){
                if(!iter_sorting_swap(j, j - 1)) break;
            }
        }

        return;
    }

}