/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    class SortBase{
    protected:
        //�\�[�g����v�f�������_���ɐݒ肷��
        void initArray(RandomIter first, RandomIter last, int max = 0, int min = 0){
            std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));       //�[�������̐ݒ�
            std::uniform_int_distribution<> rnd_val(min, max);               //��l���z�����̎w��

            //�l��ݒu
            for(RandomIter e = first; e != last; ++e){
                *e = min < max ? rnd_val(mt) : mt();
            }

            return;
        }

        //2�̃C�e���[�^������ăX���b�v����w���p�֐�
        template<class __RandomIter, class Predicate = std::less<class std::iterator_traits<__RandomIter>::value_type>>
        static inline bool iter_sorting_swap(__RandomIter a, __RandomIter b, Predicate pred = Predicate()){
            if (a > b) return iter_sorting_swap(b, a);  //arguments must be a <= b
            return pred(*b, *a) ? std::iter_swap(a, b), true : false;
        }

    public:
        //�z��v�f�̕\��
        void showArray(RandomIter first, RandomIter last){
            for(RandomIter e = first; e != last; ++e){
                std::cout << *e << ' ';
            }

            return;
        }
    };

}