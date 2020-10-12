/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    class SortBase{
    protected:
        //ソートする要素をランダムに設定する
        void initArray(RandomIter first, RandomIter last, int max = 0, int min = 0){
            std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));       //擬似乱数の設定
            std::uniform_int_distribution<> rnd_val(min, max);               //一様分布乱数の指定

            //値を設置
            for(RandomIter e = first; e != last; ++e){
                *e = min < max ? rnd_val(mt) : mt();
            }

            return;
        }

        //2つのイテレータを取ってスワップするヘルパ関数
        template<class __RandomIter, class Predicate = std::less<class std::iterator_traits<__RandomIter>::value_type>>
        static inline bool iter_sorting_swap(__RandomIter a, __RandomIter b, Predicate pred = Predicate()){
            if (a > b) return iter_sorting_swap(b, a);  //arguments must be a <= b
            return pred(*b, *a) ? std::iter_swap(a, b), true : false;
        }

    public:
        //配列要素の表示
        void showArray(RandomIter first, RandomIter last){
            for(RandomIter e = first; e != last; ++e){
                std::cout << *e << ' ';
            }

            return;
        }
    };

}