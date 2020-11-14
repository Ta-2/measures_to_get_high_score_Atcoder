/*
 *  ABC035_D
 *  https://atcoder.jp/contests/abc035/tasks/abc035_d
 *
 *  -�_�C�N�X�g���@�̎���-
 *
*/

#include <vector>
#include <queue>
#include <numeric>

/*----------��������Dijkstra�@�̎���----------*/

template <typename Ty>
class Graph {
private:
    //�������\���萔
    const Ty INF = std::numeric_limits<Ty>::max();

    //�ӂ̍\����
    struct Edge{
        Ty to;   //�s����̒��_
        Ty time; //to�ɍs���̂ɂ����鎞��
    };

    //�אڃ��X�g: G[i] = (j, time) -> ���_i����j�Ɏ���time�Ői�߂�
    std::vector<std::vector<Edge>> G;

public:
    //�ŒZ���Ԃ̊i�[
    std::vector<Ty> d;

    //�R���X�g���N�^
    Graph(Ty n): G(n), d(n, INF) {}

    //���_s���璸�_t�ւ̎���time�̕ӂ𒣂�
    void AddEdge(Ty _s, Ty _to, Ty _time) {
        Edge E;
        E.to = _to;
        E.time = _time;

        //�O���t��_s�Ԗڂ�(_to, _time)��push_back����
        G[_s].push_back(E);

        return;
    }

    //���_s����e���_�ւ̍ŒZ���Ԃ̒T��(�_�C�N�X�g���@)
    void Dijkstra(Ty s) {
        d[s] = 0;               //���_s(�n�_)�܂ł̍ŒZ���Ԃ�0�ɏ���������

        std::priority_queue
        <std::pair<Ty, Ty>,                 //�v�f�̌^
         std::vector<std::pair<Ty, Ty>>,    //�v�f�̃R���e�i
         std::greater<std::pair<Ty, Ty>>>   //�v�f�̔�r�֐�
        que;

        que.push(std::pair<Ty, Ty>(d[s], s));  //(time, to)�̌`�����Ă���̂Œ���

        while(!que.empty()){
            std::pair<Ty, Ty> p = que.top();
            que.pop();

            Ty v = p.second;

            for(auto &x : G[v]){
                if(d[x.to] > d[v] + x.time){    //(*1)�Q��

                    //���_v����������Ē��_x.to�ɒ����ŒZ���Ԃ̍X�V
                    d[x.to] = d[v] + x.time;

                    //�i�񂾐�̒��_x.to�̏���push����
                    que.push(std::pair<Ty, Ty>(d[x.to], x.to));
                }
            }
        }

        return;
    }
};

/*----------Dijkstra�@�̎��������܂�----------*/

#include <iostream>

using ll = long long;

//�ő�l�X�V�֐�
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b)
{ return a < b && (a = b, true); }

int main() {
    //n:��(���_)�̐�, m:��(��)�̐�, t:�������
    ll n, m, t;
    std::cin >> n >> m >> t;

    //������
    ll ans = 0;

    //���ꂼ��̒��̏������ɉ��Z�������z
    std::vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    Graph<ll> G1(n);            //�������O���t�̃C���X�^���X��
    Graph<ll> G2(n);            //�t�����O���t�̃C���X�^���X��

    for(int i = 0; i < m; ++i) {
        ll a, b, c;             //a�Ԃ̒�����b�Ԃ̒��ֈړ�����̂�c��������
        std::cin >> a >> b >> c;
        --a; --b;               //�z��̓Y������0����n�܂�̂Ńf�N�������g����

        G1.AddEdge(a, b, c);    //�������O���t�̕ӂ𒣂�
        G2.AddEdge(b, a, c);    //�t�����O���t�̕ӂ𒣂�
    }

    G1.Dijkstra(0);     //0����o���������̍ŒZ���Ԃ̒T��(������)
    G2.Dijkstra(0);     //0����o���������̍ŒZ���Ԃ̒T��(�t����)

    for(int i = 0; i < n; ++i) {
        //(*2)�Q��
        if(t < G1.d[i] + G2.d[i]) continue;

        //(*3)�Q��
        ll money = a[i] * (t - (G1.d[i] + G2.d[i]));

        //�������̍ő�l�̍X�V
        chmax(ans, money);
    }

    //�������̍ő�l(����)�̏o��
    std::cout << ans << '\n';

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
