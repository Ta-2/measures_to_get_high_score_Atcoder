/**
 * ※このファイル単体では動作しません。Sort.hppにincludeして使用してください。
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Quick(RandomIter first, RandomIter last, bool display_result){

        quick_sort(first, last);

        if(display_result){
            std::cout << '\n';
            showArray(first, last);
        }

        return;
    }

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Quick_Insertion(RandomIter first, RandomIter last, bool display_result){

        partial_quick_sort(first, last);
        Insertion(first, last);

        if(display_result){
            std::cout << '\n';
            showArray(first, last);
        }

        return;
    }

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Intro(RandomIter first, RandomIter last, bool display_result){

        partial_quick_sort(first, last);
        Heap_itr(first, last);

        if(display_result){
            std::cout << '\n';
            showArray(first, last);
        }

        return;
    }

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Quick_Shell(RandomIter first, RandomIter last, bool display_result, bool arr_gap){

        partial_quick_sort(first, last);
        if(arr_gap){
            Container gap = make_gap(first, last);
            Shell(first, last, gap);
        }
        else{
            Shell(first, last);
        }

        if(display_result){
            std::cout << '\n';
            showArray(first, last);
        }

        return;
    }

}