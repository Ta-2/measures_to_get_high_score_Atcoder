/**
 * ※このファイル単体では動作しません。Sort.hppにincludeして使用してください。
*/

#pragma once

#define HEAP_Itr

namespace kya{

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Heap_itr(RandomIter first, RandomIter last, bool display_result, bool greater){

        for(RandomIter it = first; it != last; ++it){
            push(*it);
        }

        if(!greater){
            for(RandomIter it = last - 1; it != first - 1; --it){
                *it = top();
                pop();
            }
        }
        else{
            for(RandomIter it = first; it != last; ++it){
                *it = top();
                pop();
            }
        }

        if(display_result){
            std::cout << '\n';
            showArray(first, last);
        }

        return;
    }

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Heap_itr(RandomIter first, RandomIter last){

        for(RandomIter it = first; it != last; ++it){
            push(*it);
        }

        for(RandomIter it = last - 1; it != first - 1; --it){
            *it = top();
            pop();
        }
        return;
    }

}