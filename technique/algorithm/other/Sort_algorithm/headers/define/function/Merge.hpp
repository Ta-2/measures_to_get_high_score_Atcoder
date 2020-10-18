/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.hpp��include���Ďg�p���Ă��������B
*/

#pragma once
namespace kya{

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Merge(RandomIter first, RandomIter last, bool display_result){

        merge_sort(first, last);

        if(display_result){
            std::cout << '\n';
            showArray(first, last);
        }

        return;
    }

}