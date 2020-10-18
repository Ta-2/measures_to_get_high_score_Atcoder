/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    class MergeBase{
    protected:
        void merge_sort(RandomIter first, RandomIter last){

            auto diff = last - first;

            if(diff <= 1) return;

            auto middle = first + diff / 2;

            this->merge_sort(first, middle);
            this->merge_sort(middle, last);

            std::inplace_merge(first, middle, last);

            // this->__merge(first, middle, last);      <- ���̃R�����g�A�E�g�͊O���Ă͂����Ȃ�

            return;
        }


    /*----------���O�������������������߂��B----------*/
    //�ȉ��A���������삵�܂���B

        void __merge(RandomIter first, RandomIter middle, RandomIter last){
            std::vector<int> numbers;
            std::vector<int> temp;

            //temp�̃C�e���[�^
            auto tmp_pos = first;
            //�z��̍����̉E�[
            auto left_end = middle;
            //�z��̗v�f��
            auto num_elements = last - first + 1;

            //2�̃��X�g�ɗv�f���c���Ă���
            for(; (first <= left_end) && (middle <= last); ++first, ++tmp_pos){
                *first <= *middle ? *tmp_pos = *first : *tmp_pos = *middle;
            }

            //�����̃��X�g
            for(; first <= left_end; ++first, ++tmp_pos){
                *tmp_pos = *first;
            }

            //�E���̃��X�g
            for(; middle <= last; ++middle, ++tmp_pos){
                *tmp_pos = *middle;
            }

            //�����ɐ��񂷂�悤�ЂƂ̃��X�g�ɂ܂Ƃ߂�
            for(int i = 0; i <= num_elements; ++i, --last){
                *last = *last;
            }

            return;
        }
    };

}