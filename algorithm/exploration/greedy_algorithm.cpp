/*
 *  �L�[�G���X�v���O���~���O�R���e�X�g2020_B
 *  https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
 *
 *  -�×~�@�̎���-
 *
*/

//#define _GLIBCXX_DEBUG    <- debug
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;          //���{�b�g�̐�
    cin >> n;

    vector<pair<int, int>> p;   //���ꂼ��̃��{�b�g�̘r�̉���̗��[���i�[
    p.reserve(n);

    for(int i = 0; i < n; ++i){
        int x, l;   //x: ���{�b�g�̍��W, l: ���{�b�g�̘r�̒���
        cin >> x >> l;

        p.push_back(make_pair(x + l, x - l));   //(�E�[�̍��W, ���[�̍��W)
    }

    sort(p.begin(), p.end());   //vector<pair>��sort�́Afirst�ɒ��ڂ��čs��

    int res = 0;                //��菜�����{�b�g�̐�
    int x = p[0].first;         //�c�����{�b�g�̉E�[�̍��W

    for(int i = 1; i < n; ++i){
        if(x > p[i].second){    //�c�����{�b�g�̉E�[�̍��W�����̃��{�b�g�̍��[�̍��W���傫���Ƃ��A
            ++res;              //���̃��{�b�g����菜��
        }
        else{
            x = p[i].first;     //��菜���Ȃ��Ȃ�΁A���̃��{�b�g�̉E�[�̍��W�ɍX�V����
        }
    }

    cout << n - res << endl;

    return 0;
}

/*
�|�C���g:   ���݂̏�ԂƂ��̎��̏�ԂɁw�����x���ڂ��čœK������̂��A�×~�@
            ���ꂾ���łȂ��A�S�̂̏�Ԃɂ����ڂ��čœK������̂��A���I�v��@
            �œK���������̂��ŋ𒼂ɑS�p�^�[����񋓂���̂��A�S�T��

            (�����̕\���������Ă��邩�ǂ����͕�����Ȃ�)

*/