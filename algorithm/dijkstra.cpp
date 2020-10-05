/*
 *  ABC035_D
 *  https://atcoder.jp/contests/abc035/tasks/abc035_d
 *
 *  -�_�C�N�X�g���@�̎���-
 *
*/

//#define _GLIBCXX_DEBUG   <- debug
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//�������\���萔
constexpr long long inf  = (long long)1e18 + 1;

//�ő�l�X�V�֐�
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }


/*----------��������Dijkstra�@�̎���----------*/

//�ӂ̍\����
struct edge{
    long long to;   //�s����̒��_
    long long time; //to�ɍs���̂ɂ����鎞��
};

class graph{
private:
    vector<vector<edge>> G; //�O���t�z��
                            //G[i] = (j, time) -> ���_i����j�Ɏ���time�Ői�߂�

public:
    vector<long long> d;    //�ŒZ���Ԃ̊i�[

//�R���X�g���N�^
    graph(long long n);

//���_s���璸�_t�ւ̎���time�̕ӂ𒣂�
    void add_edge(long long _s, long long _to, long long _time);

//���_s����e���_�ւ̍ŒZ���Ԃ̒T��(�_�C�N�X�g���@)
    void dijkstra(long long s);
};

graph::graph(long long n){
    G.resize(n);
    d.resize(n);
    for(int i = 0; i < n; i++){
        d[i] = inf;         //�ŒZ���Ԃ𖳌���ŏ�����
    }
}

void graph::add_edge(long long _s, long long _to, long long _time){
    edge E;
    E.to = _to;
    E.time = _time;
    G[_s].push_back(E);     //�O���t��_s�Ԗڂ�(_to, _time)��push_back����

    return;
}

void graph::dijkstra(long long s){
    d[s] = 0;               //���_s(�n�_)�܂ł̍ŒZ���Ԃ�0�ɏ���������

    priority_queue
    < pair<long long, long long>,           //�v�f�̌^
      vector<pair<long long, long long>>,   //�v�f�̃R���e�i
      greater<pair<long long, long long>> > //�v�f�̔�r�֐�
      que;

    que.push(pair<long long, long long>(d[s], s));  //(time, to)�̌`�����Ă���̂Œ���

    while(!que.empty()){
        pair<long long, long long> p = que.top();
        que.pop();

        long long v = p.second;

        for(auto &x : G[v]){
            if(d[x.to] > d[v] + x.time){    //(*1)�Q��

                //���_v����������Ē��_x.to�ɒ����ŒZ���Ԃ̍X�V
                d[x.to] = d[v] + x.time;

                //�i�񂾐�̒��_x.to�̏���push����
                que.push(pair<long long, long long>(d[x.to], x.to));
            }
        }
    }

    return;
}

/*----------Dijkstra�@�̎��������܂�----------*/


int main() {
    long long n, m, t;          //n:��(���_)�̐�, m:��(��)�̐�, t:�������
    cin >> n >> m >> t;
    long long ans = 0;          //������

    vector<long long> a(n);     //���ꂼ��̒��̏������ɉ��Z�������z
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    graph G1(n);                //�������O���t�̃C���X�^���X��
    graph G2(n);                //�t�����O���t�̃C���X�^���X��

    for(int i = 0; i < m; ++i){
        long long a, b, c;      //a�Ԃ̒�����b�Ԃ̒��ֈړ�����̂�c��������
        cin >> a >> b >> c;
        --a; --b;               //�z��̓Y������0����n�܂�̂Ńf�N�������g����

        G1.add_edge(a, b, c);   //�������O���t�̕ӂ𒣂�
        G2.add_edge(b, a, c);   //�t�����O���t�̕ӂ𒣂�
    }

    G1.dijkstra(0);             //0����o���������̍ŒZ���Ԃ̒T��(������)
    G2.dijkstra(0);             //0����o���������̍ŒZ���Ԃ̒T��(�t����)

    for(int i = 0; i < n; ++i){
        if(t < G1.d[i] + G2.d[i]) continue; //(*2)�Q��

        long long money = a[i] * (t - (G1.d[i] + G2.d[i])); //(*3)�Q��

        chmax(ans, money);      //�������̍ő�l�̍X�V
    }

    cout << ans << '\n';        //�������̍ő�l(����)�̏o��

return 0;
}

/*
��:

(*1)    if(d[x.to] > d[v] + x.time) �́A��������
        ���ӂ́A�u���_x.to�܂łɕK�v�ȍŒZ���ԁv�A
        �E�ӂ́A�u�����钸�_v�܂ł̍ŒZ���ԂɁA���_x.to�ɐi�ނ��߂̎��Ԃ𑫂������́v
        �ł���A���̏����𖞂����Ȃ����A���_v -> x.to�̃��[�g�͒ʂ�Ȃ�(continue)
        �Ƃ����Ӗ�������

(*2)    (G1.d[i] + G2.d[i]) �́A�n�_���璸�_i�܂ł̉����̎��Ԃ̍��v��\��
        ��蓹�����ɉ������������̃R�X�g���������t�𒴂��Ă���Ƃ��͒T�����Ȃ��A
        �Ƃ����Ӗ�������

(*3)    �܂����̖��ň�ԉ������Ă����ׂ����́A�w�؍݂��ׂ����͂���1���x�Ƃ������ƁB
        �����̒��ɑ؍݂�������A���Ԑ���(�����ł�t)�ɊԂɍ������̂����A
        �ł����Z�������z�̑傫�����ɍő���؍݂������������B

        �����Ȃ�΁A���߂鏊�����̍ő�l�́A
        �w����t�ȓ��̎��Ԃōs���钬(*2�Q��)�̂����A�ł��P�ʎ��ԓ�����̉��Z�z(a[i])�̑傫�����x
        �ɁA�w�����ړ����ԈȊO�̎c��̎���(t - (G1.d[i] + G2.d[i]))�x���|�����l�ɂȂ�

*/