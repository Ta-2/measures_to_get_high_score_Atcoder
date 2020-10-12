/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

namespace kya{

    template<class RandomIter, class Container>
    class Sort : public    SortBase    <std::vector<int>::iterator, std::vector<int>>,
                 protected MergeBase   <std::vector<int>::iterator, std::vector<int>>,
                 protected QuickBase   <std::vector<int>::iterator, std::vector<int>>,
                 protected Binary_Heap <int>
    {
    protected:
        void Insertion(RandomIter first, RandomIter last);
        void Heap_itr(RandomIter first, RandomIter last);
        void Shell(RandomIter first, RandomIter last);
        Container make_gap(RandomIter first, RandomIter last);  //�V�F���\�[�g�̃M���b�v������߂�
        void Shell(RandomIter first, RandomIter last, Container gap);
        inline void Distribute(int value, Container &vec);

    public:
        //�R���X�g���N�^(n: �z��̗v�f�̍ő�l)
        Sort(Container &v, int n){          //v�͎Q�Ɠn���ɂ��Ȃ��ƑS�v�f��0�ɂȂ��Ă��܂�
            initArray(v.begin(), v.end(), n);
        }

        //�R���X�g���N�^(n: �z��̗v�f�̍ő�l, m: �z��̗v�f�̍ŏ��l)
        Sort(Container &v, int n, int m){
            initArray(v.begin(), v.end(), n, m);
        }

        //�o�u���\�[�g(cnt:�u�Z��ځc�v��\�����邩�ǂ���, display_middle: �\�[�g�̓r���o�߂�\�����邩�ǂ���, display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���)
        void Bubble(RandomIter first, RandomIter last, bool cnt, bool display_middle, bool display_result);

        //�I���\�[�g(cnt:�u�Z��ځc�v��\�����邩�ǂ���, display_middle: �\�[�g�̓r���o�߂�\�����邩�ǂ���, display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���)
        void Selection(RandomIter first, RandomIter last, bool cnt, bool display_middle, bool display_result);

        //�}���\�[�g(cnt:�u�Z��ځc�v��\�����邩�ǂ���, display_middle: �\�[�g�̓r���o�߂�\�����邩�ǂ���, display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���)
        void Insertion(RandomIter first, RandomIter last, bool cnt, bool display_middle, bool display_result);

        //�}�[�W�\�[�g(display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���)
        void Merge(RandomIter first, RandomIter last, bool display_result);

        //�N�C�b�N�\�[�g(display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���)
        void Quick(RandomIter first, RandomIter last, bool display_result);

        //�N�C�b�N-�}���\�[�g(display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���)
        void Quick_Insertion(RandomIter first, RandomIter last, bool display_result);

        //�q�[�v�\�[�g(�z�����)(display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���)
        void Heap(Container &vec7, bool display_result);

        //�q�[�v�\�[�g(�C�e���[�^����)(display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���, greater: true�̎��A�~���Ƀ\�[�g����)
        void Heap_itr(RandomIter first, RandomIter last, bool display_result, bool greater = false);

        //�C���g���\�[�g(display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���)
        void Intro(RandomIter first, RandomIter last, bool display_result);

        //�V�F���\�[�g(display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���)
        void Shell(RandomIter first, RandomIter last, bool display_result);

        //�N�C�b�N-�V�F���\�[�g(display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���, arr_gap: �M���b�v����g�p���邩�ǂ���)
        void Quick_Shell(RandomIter first, RandomIter last, bool display_result, bool arr_gap);

        //�O���r�e�B�\�\�[�g(display_result: �\�[�g�̌��ʂ�\�����邩�ǂ���)
        Container Gravity(Container vec11);

    };

}

/*�\�[�g�֐��̒�`�w�b�_*/
#include "../function/Bubble.hpp"
#include "../function/Selection.hpp"
#include "../function/Insertion.hpp"
#include "../function/Merge.hpp"
#include "../function/Quick.hpp"
// #include "../function/Heap.hpp"    //�����2�̃w�b�_�̂���
#include "../function/Heap_itr.hpp"   //�u�Е������v���C���N���[�h���邱�ƁB(#define�̋�����h������)
#include "../function/Shell.hpp"
#include "../function/Gravity.hpp"
