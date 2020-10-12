/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
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

            // this->__merge(first, middle, last);      <- このコメントアウトは外してはいけない

            return;
        }


    /*----------自前実装したかったが諦めた。----------*/
    //以下、正しく動作しません。

        void __merge(RandomIter first, RandomIter middle, RandomIter last){
            std::vector<int> numbers;
            std::vector<int> temp;

            //tempのイテレータ
            auto tmp_pos = first;
            //配列の左側の右端
            auto left_end = middle;
            //配列の要素数
            auto num_elements = last - first + 1;

            //2つのリストに要素が残っている
            for(; (first <= left_end) && (middle <= last); ++first, ++tmp_pos){
                *first <= *middle ? *tmp_pos = *first : *tmp_pos = *middle;
            }

            //左側のリスト
            for(; first <= left_end; ++first, ++tmp_pos){
                *tmp_pos = *first;
            }

            //右側のリスト
            for(; middle <= last; ++middle, ++tmp_pos){
                *tmp_pos = *middle;
            }

            //昇順に整列するようひとつのリストにまとめる
            for(int i = 0; i <= num_elements; ++i, --last){
                *last = *last;
            }

            return;
        }
    };

}