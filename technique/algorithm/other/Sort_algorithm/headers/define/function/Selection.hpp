/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.hpp��include���Ďg�p���Ă��������B
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Selection(RandomIter first, RandomIter last, bool cnt, bool display_middle, bool display_result){
        int count = 0;
        int COUNT = 0;

        if(last - first <= 1) return;

        // �\�[�g�����{
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
                    std::cout << "(" << count << "���)";
                }
                std::cout << '\n';
            }
        }

        if(display_result){
            std::cout << '\n';
            showArray(first, last);
        }
        std::cout << '\n' << "Selection_Sort �� " << count << " ��(���� " << count - COUNT << " ��)�̑���Ŋ������܂����B";
        std::cout << "(����: " << COUNT << "��)" << '\n';

        return;
    }

}