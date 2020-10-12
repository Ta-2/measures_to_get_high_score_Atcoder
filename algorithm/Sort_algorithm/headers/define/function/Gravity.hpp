/**
 * ※このファイル単体では動作しません。Sort.hppにincludeして使用してください。
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    inline void Sort<RandomIter, Container>::Distribute(int value, Container &vec){
        if (value > (int)vec.size()){
            vec.resize(value);
        }

        for (int i = 0; i < value; ++i){
            ++vec[i];
        }

        return;
    }

    template<class RandomIter, class Container>
    Container Sort<RandomIter, Container>::Gravity(Container input){
        Container middle;
        int INPUT_SIZE = input.size();
        for (int i = 0; i < INPUT_SIZE; ++i)     Distribute(input[i], middle);

        Container ret;
        int MIDDLE_SIZE = middle.size();
        for (int i = 0; i < MIDDLE_SIZE; ++i)    Distribute(middle[i], ret);

        return ret;
    }

}