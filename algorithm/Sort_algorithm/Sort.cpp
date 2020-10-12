/****************�w�b�_�Q****************/

/*c++�W�����C�u�����w�b�_*/
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

/*�\�[�g�֐��̊�b�֐��E�N���X�̃w�b�_*/
#include "headers/define/class/Sort_Base.hpp"
#include "headers/define/class/Merge_Base.hpp"
#include "headers/define/class/Quick_Base.hpp"
#include "headers/define/class/Binary_heap.hpp"

/*�\�[�g�֐��S�̂��Ǘ�����N���X�̃w�b�_*/
#include "headers/define/class/Sort.hpp"

#define CMD_RUN 0   //cmd��Ŏ��s����������1�ɂ���

/****************���C���֐�****************/
int main(){

#if CMD_RUN
printf("Start sort to press any key...");
getchar();
#endif

/*�\�[�g���s���z��̑傫���Ɨv�f�̎�肤��͈͂����炩���ߎw��*/
    constexpr int n = (int)1e3;
    constexpr int MAX = 32;
    constexpr int MIN = 1;  //Gravity_Sort�g�p���́AMIN��K��1�ȏ�ɂ��邱�ƁB

    std::cout << "Sort����z��̗v�f���� " << n << " �ł��B\n";
    std::cout << "Sort����z��̍ő�l�� " << MAX << " �ł��B\n";
    std::cout << "Sort����z��̍ŏ��l�� " << MIN << " �ł��B\n\n";

    std::cout << "Sort����z��̐��������Ă��܂�...\n";

/*�\�[�g���s���f�[�^�̊i�[�z��*/
    std::vector<int> vec0(n);        //STL_sort() ... �W���\�[�g


/*Sort�I�u�W�F�N�g�̐���(vec0�z����A�����_���ȗv�f�ŏ�����)*/
    kya::Sort<std::vector<int>::iterator, std::vector<int>>
    Sort(vec0, MAX, MIN);


/*�ȍ~�A�������ςݔz��̃R�s�[����*/
    std::vector<int> rev_vec0 = vec0;   //reverse_STL_sort()
    std::vector<int> vec00 = vec0;      //STL_stable_sort()
    std::vector<int> vec1  = vec0;      //Bubble_Sort
    std::vector<int> vec2  = vec0;      //Selection_Sort
    std::vector<int> vec3  = vec0;      //Insertion_Sort
    std::vector<int> vec4  = vec0;      //Merge_Sort
    std::vector<int> vec5  = vec0;      //Quick_Sort
    std::vector<int> vec6  = vec0;      //Quick_Insertion_Sort
    std::vector<int> vec7  = vec0;      //Heap_Sort
    std::vector<int> vec8  = vec0;      //Intro_Sort
    std::vector<int> vec9  = vec0;      //Shell_Sort
    std::vector<int> vec10 = vec0;      //Quick_Shell_Sort
    std::vector<int> vec11 = vec0;      //Gravity_Sort
    std::vector<int> Vec11;             //Gravity_Sort(result)

    std::cout << "Sort����z��̐������������܂����B\n\n";


/*�\�[�g�֐��̎��s�ƌ��ʂ̕\��(�g��Ȃ��\�[�g�̃w�b�_�̓R�����g�A�E�g����)*/
    #include "headers/output/STL_stable.hpp"
    #include "headers/output/Bubble.hpp"
    #include "headers/output/Selection.hpp"
    #include "headers/output/Insertion.hpp"
    #include "headers/output/Merge.hpp"
    #include "headers/output/Quick.hpp"
    #include "headers/output/Quick_Insertion.hpp"
    #include "headers/output/Heap.hpp"
    #include "headers/output/Intro.hpp"
    #include "headers/output/Shell.hpp"
    #include "headers/output/Quick_Shell.hpp"
    #include "headers/output/Gravity.hpp"

/*���̃w�b�_�͊�{�I�ɃR�����g�A�E�g���Ȃ�����*/
    #include "headers/output/STL.hpp"


/*�e�\�[�g�̌��ʂ��W���\�[�g�̌��ʂɈ�v���邩�ǂ����̊m�F(��ŃR�����g�A�E�g�����\�[�g�ɑΉ�����������̓R�����g�A�E�g����)*/
    if(
        vec0 == vec00 &&    //STL_stable_sort()
        vec0 == vec1  &&    //Bubble
        vec0 == vec2  &&    //Selection
        vec0 == vec3  &&    //Insertion
        vec0 == vec4  &&    //Merge
        vec0 == vec5  &&    //Quick
        vec0 == vec6  &&    //Quick_Insertion
        vec0 == vec7  &&    //Heap
        vec0 == vec8  &&    //Intro
        vec0 == vec9  &&    //Shell
        vec0 == vec10 &&    //Quick_Shell
        rev_vec0 == Vec11 &&    //Gravity
        true
    ){ std::cout << "�eSort�ɂ��o�͂͂��ׂĊ�Ɉ�v���Ă��܂��B\n"; }
    else{ std::cout << "�eSort�ɂ��o�͂̂ǂꂩ����Ɉ�v���܂���B\n"; }

#if CMD_RUN
printf("End exe to press any key...");
getchar();
#endif

    return 0;
}