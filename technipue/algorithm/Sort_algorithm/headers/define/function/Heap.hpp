/**
 * ※このファイル単体では動作しません。Sort.hppにincludeして使用してください。
*/

#pragma once

#define HEAP_Con

namespace kya{

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Heap(Container &vec7, bool display_result){

        for(auto &x : vec7){
            push(x);
        }

        for(int i = (int)vec7.size() - 1; i >= 0; --i){
            vec7[i] = top();
            pop();
        }

        RandomIter first = vec7.begin();
        RandomIter last = vec7.end();

        if(display_result){
            std::cout << '\n';
            showArray(first, last);
        }

        return;
    }

}