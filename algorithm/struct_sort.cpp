/**
 * ABC_128_B
 * https://atcoder.jp/contests/abc128/tasks/abc128_b
 *
 * -�\���́E�N���X�̃\�[�g-
 *
 * C++��STL�ł́A�I�u�W�F�N�g�̔�r�ɂ͈ÖٓI��operator<���g�p����Ă���B
 * �\���̂͂��̂܂܂ł͔�r�ł��Ȃ��̂ŉ��Z�q�̃I�[�o�[���[�h������B(��r�֐��̎����ł��ǂ�)
 *
 * ���Z�q�̃I�[�o�[���[�h������΁Amax��lower_bound�����l�Ɏg�p�ł���悤�ɂȂ�B
 *
*/

#include <iostream>
#include <algorithm>
using namespace std;

class restaurant{
public:
	string city;
	int score;
	int num;

	inline bool operator < (const restaurant &other) const{
		return  (this->city != other.city) ?    //city���Ⴄ���ǂ�������
                (this->city  < other.city) :    //�Ⴄ���Acity��������
                (this->score > other.score);    //�������Ascore���~����
	}
};

int main(){
	int n; cin >> n;
    restaurant res[105];

	for(int i = 1; i <= n; ++i){
        string s; int p;
		cin >> s >> p;
        res[i].city = s;
        res[i].score = p;
		res[i].num = i;
	}

	sort(res + 1, res + n + 1);     //res�́A�z��̐擪�̃C�e���[�^(���m�ɂ̓|�C���^)���w��

	for(int i = 1; i <= n; ++i){
        cout << res[i].num << endl;
    }

return 0;
}