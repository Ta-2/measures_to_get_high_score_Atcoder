/**
 * ※このファイル単体では動作しません。Sort.hppにincludeして使用してください。
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Shell(RandomIter first, RandomIter last, bool display_result){
        int gap = 7;
        int temp;

        while (gap > 0){
            for (RandomIter it = first; it != last; ++it){
                RandomIter j = it;
                temp = *it;
                while ((std::distance(first, j) >= gap) && (*(j - gap) > temp)){
                    *j = *(j - gap);
                    j -= gap;
                }

                *j = temp;
            }

            if (gap/2 != 0)       gap /= 2;

            else if (gap == 1)    gap = 0;

            else                  gap = 1;

        }

        if(display_result){
            std::cout << '\n';
            showArray(first, last);
        }

        return;
    }

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Shell(RandomIter first, RandomIter last){
        int gap = 3;
        int temp;

        while (gap > 0){
            for (RandomIter it = first; it != last; ++it){
                RandomIter j = it;
                temp = *it;
                while ((std::distance(first, j) >= gap) && (*(j - gap) > temp)){
                    *j = *(j - gap);
                    j -= gap;
                }

                *j = temp;
            }

            if (gap/2 != 0)       gap /= 2;

            else if (gap == 1)    gap = 0;

            else                  gap = 1;

        }

        return;
    }

    template<class RandomIter, class Container>
    void Sort<RandomIter, Container>::Shell(RandomIter first, RandomIter last, Container gap){

        int temp;

        for(RandomIter GAP = gap.end() - 1, BEGIN = gap.begin(); GAP != BEGIN - 1; --GAP){
            for (RandomIter it = first; it != last; ++it){
                RandomIter j = it;
                temp = *it;
                while ((std::distance(first, j) >= *GAP) && (*(j - *GAP) > temp)){
                    *j = *(j - *GAP);
                    j -= *GAP;
                }

                *j = temp;
            }
        }

        return;
    }

    template<class RandomIter, class Container>
    Container Sort<RandomIter, Container>::make_gap(RandomIter first, RandomIter last){
        int vec_size = std::distance(first, last);
        int gap_size = log(vec_size);
        Container gap(gap_size);
        for(int p = 1; p <= gap_size; ++p){
            gap[p-1] = (pow(3, p) - 1) / 2;
        }

        return gap;
    }

}