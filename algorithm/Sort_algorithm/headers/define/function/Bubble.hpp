/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.hpp��include���Ďg�p���Ă��������B
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Bubble(RandomIter first, RandomIter last, bool cnt, bool display_middle, bool display_result){
        int count = 0;

        if(last - first <= 1) return;

        // �\�[�g�����{
        for(RandomIter i = first; i != last; ++i){
            bool complete = true;   //�v�f�̓���ւ�����������false�ɂȂ�

            for(RandomIter j = last - 1; j != i; --j){
                if(iter_sorting_swap(j, j - 1)){
                    complete = false;
                }
            }

            ++count;

            if(complete){
                break;     //��x���v�f�̓���ւ����Ȃ�(�\�[�g����������)���A�����𔲂���
            }

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
        std::cout << '\n' << "Bubble_Sort �� " << count - 1 << " ��̑���Ŋ������܂����B" << '\n';

        return;
    }

}