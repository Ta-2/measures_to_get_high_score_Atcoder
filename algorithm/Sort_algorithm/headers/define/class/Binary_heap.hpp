#pragma once

#include <vector>

namespace kya{

    //�񕪃q�[�v�N���X
    template<class Ty>
    class Binary_Heap{
    protected:

        //�q�[�v�̗v�f���i�[����z��
        std::vector<Ty> heap;


        //�q�[�v�ɒlv��}��
        void push(Ty v){
            heap.push_back(v);              //�Ō���ɒl�ǉ�

            int i = (int)heap.size() - 1;   //�l�̌��݂̃m�[�h�ԍ�(�����l�͍Ō��)

            while (i > 0){//�召��r

                int parent = (i - 1) / 2;       //�e�̃m�[�h�ԍ�

                if (heap[parent] >= v){
                    //�t�]���Ȃ�������A�u�t�]���Ȃ��Ȃ������_�̃m�[�h�ԍ���ێ����āv���[�v�𔲂���
                    break;
                }

                heap[i] = heap[parent];        //�����̃m�[�h��e�̒l��
                i = parent;                    //�����͌��X�e�̂����m�[�h�ɍs��
            }

            //����v�͂��̃m�[�h�Ɋi�[�����
            heap[i] = v;

            return;
        }


        //�q�[�v�̍ő�l�𓾂�(�q�[�v����̎���-1��Ԃ�)
        Ty top(){
            return !heap.empty() ? heap[0] : -1;
        }


        //�q�[�v�̍ő�l���폜(���ăq�[�v��g�ݒ���)
        void pop(){
            if (heap.empty()) return;       //�q�[�v����̎��͉������Ȃ�

            Ty v = heap.back();            //���[�g�ɂ��ꂩ�玝���Ă���l(�q�[�v�̍Ō��)

            heap.pop_back();                //�ő�l(���[�g)�̍폜(�ő�l�𓾂�������pop���Ăяo���u�O�Ɂvtop�œ���)

            int i = 0;                      //������~�낵�Ă���

            while (i * 2 + 1 < (int)heap.size()) {
                int child1 = i * 2 + 1;
                int child2 = i * 2 + 2;
                //�q�����m���r���đ傫������child1�Ƃ���
                if (child2 < (int)heap.size() && heap[child1] < heap[child2]){
                    child1 = child2;
                }

                if (heap[child1] <= v){
                    //�t�]���Ȃ�������A�u�t�]���Ȃ��Ȃ������_�̃m�[�h�ԍ���ێ����āv���[�v�𔲂���
                    break;
                }

                heap[i] = heap[child1];         //�����̃m�[�h���q�̒l��
                i = child1;                     //�����͌��X�q�̂����m�[�h�ɍs��
            }

            //���q�[�v�̍Ō���͂��̃m�[�h�Ɋi�[����A�g�ݒ�������������
            heap[i] = v;

            return;
        }
    };

}