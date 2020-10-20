#include <iostream>
#include <vector>
using namespace std;

struct Collection{
	vector<int>member;	//��舵���v�f�̔z��(0�`�v�f��-1�܂ł̊ԂŏW���̑�����s��)
						//(���v����ɗv�f�Ƃ���(�v�f���A�v�f��+1�A...)�̐����͈����Ȃ�)
	
	Collection(int N){
		member = vector<int>(N, -1);	//�v�f�����R���X�g���N�^�Őݒ肷��
		//���̂Ƃ��A�e�v�f�͂��ꂼ��v�f��1�̏W���Ƃ��Ĉ����Ă���
	}
	
	int root(int i){
		//�w�肳�ꂽ�v�f�������Ă���W���̍ő�l�v�f��T��
		//(�W���̗v�f���̓}�C�i�X�ŕ\����Ă��āA�e�v�f�͐��̐��ƌ��߂Ă���̂�
		//���ʂƏW���̗v�f���̃J�E���g�𓯎��ɂ��Ȃ��Ă���B�l�����l�V��)
		return (member[i] >= 0 ? root(member[i]): i);
	}
	
	bool conbine(int a, int b){
		int x = root(a);
		int y = root(b);
		//a��b�������W���ɏ������Ă���Ƃ��Aroot(a)��root(b)�͈�v����
		//�܂�A�����W���ɑ����Ă��邩�̖��́A
		//���ꂼ��̏W���̍ő�l�v�f�����������̖��Ɠ��l�ł���ƌ�������(�l�����l�}�W�V��)
		if(x == y)return false;
		//����Ă����ꍇ�Ax < y�̊֌W�ɒ������A
		if(x > y)swap(x, y);
		//�W���̗v�f�����Amember[y]�̕��ɉ��Z
		member[y] += member[x];
		//member[x]����y�ւƏW�����������Ă���
		member[x] = y ;
		
		return true;
	}
	
	int total(int i){
		//�W���̗v�f���́A-member[�W���̍ő�l�v�f]�Ɛ����Ă���̂�-���|����return����Ηǂ�
		return -member[root(i)];
	}
};

int main(){
	int N = 10;
	struct Collection CL(N);
	
	CL.conbine(1,2);
	CL.conbine(3,2);
	CL.conbine(1,3);
	CL.conbine(4,8);
	CL.conbine(5,7);
	CL.conbine(7,8);
	CL.conbine(8,9);
	CL.conbine(9,9);
	
	for(int i = 0; i < 10; i++)cout << CL.total(i) << endl;
	
	return 0;
}
