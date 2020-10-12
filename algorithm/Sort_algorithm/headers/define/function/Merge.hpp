/**
 * ※このファイル単体では動作しません。Sort.hppにincludeして使用してください。
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