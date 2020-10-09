/*
 *  ARC032_B
 *  https://atcoder.jp/contests/arc032/tasks/arc032_2
 *
 *  -union_find_tree�̎���-
 *
*/

//#define _GLIBCXX_DEBUG    <- debug
#include <iostream>
#include <vector>
using namespace std;


/*----------��������union_find_tree�̎���----------*/

class UnionFind{
public:
    std::vector<int> par;       //par[i]  -> i�̐e�̔ԍ�
    std::vector<int> size;      //size[i] -> �w���xi�Ɍq����v�f�̌�(�����N)
    int num;                    //�R���X�g���N�^�����̊i�[

    //�R���X�g���N�^
    UnionFind(int _n) : par(_n), size(_n, 0), num(_n){
        //�S�Ă̗v�f����(par[i] = i�ƂȂ�i)�ł���Ƃ��ď�����
        for(int i = 0; i < _n; i++) par[i] = i;
    }

    //x��������؂̍����擾
    int root(int x);

    //x��������؂̃����N���擾
    int rank(int x);

    //�ux��������؁v�Ɓuy��������؁v�𕹍�
    void unite(int x, int y);

    //x, y��������؂��������𔻒�
    bool same(int x, int y);

    //�Ɨ������؂̌����擾
    int count();

};

int UnionFind::root(int x){             //�ċA�T��
    if (par[x] == x) return x;
    return par[x] = root(par[x]);       //�����Ōo�H�̒Z�k���s��
}

int UnionFind::rank(int x){
    return size[root(x)];
}

void UnionFind::unite(int x, int y){
    if (root(x) == root(y)) return;

    if(rank(x) < rank(y)){
        par[root(x)] = root(y);         //�����N���������̖؂ɕ���
    }
    else{
        par[root(y)] = root(x);         //�����N���������̖؂ɕ���

        if(rank(x) == rank(y)){
            ++size[root(x)];            //�����N�������Ƃ��͕�������؂̃����N���C���N�������g
        }
    }

    return;
}

bool UnionFind::same(int x, int y){
    return root(x) == root(y);
}

int UnionFind::count(){
    int ret = 0;
    for(int i = 0; i < num; ++i){
        if(par[i] == i) ++ret;          //�u�؂��Ɨ����Ă���̍����Ⴄ�l�����v�Ȃ̂ŁA���̌��𐔂��Ă���
    }

    return ret;
}

/*----------union_find_tree�̎��������܂�----------*/


int main() {
    int n, m;                           //n: �����_�̌�, m: ���H�̌�
    cin >> n >> m;

    UnionFind tree(n);                  //UnionFind�N���X�̃C���X�^���X��

    vector<int> a(m), b(m);             //���H�̗��[�̌����_
    for(int i = 0; i < m; ++i){
        cin >> a[i] >> b[i];
        --a[i]; --b[i];                 //�z��̈����Ƃ��Ĉ������߃f�N�������g

        tree.unite(a[i], b[i]);         //UnionFind�؂̕���
    }

    int ans = tree.count() - 1;         //(*1)�Q��

    cout << ans << endl;

return 0;
}

/*
��:
(*1)    ���߂���̂́A�w�ǂ̌����_�ɂ��s����悤�ɂ��邽�߂̍ŏ��̓��H�ǉ����x
        ���̂��߂ɂ܂��A�w�ǂ̌����_�����H����Čq�����Ă��邩�x��
        UnionFind�ɂ���Ē��ׂ�(�q�����Ă�������_�͓���̖؂̗v�f�ƂȂ�)
        �����āA�w�ǂ̌����_�ɂ����H����čs����x�Ƃ������Ƃ́A
        �w�S�Ă̌����_���A����̖؂̗v�f�Ɋ܂܂��x���ƂƓ��l�ł���
        �䂦�ɁA���݂̓Ɨ������؂̌���������΁A���̌�����1���������̂�
        ���H�ǉ����ƂȂ�
*/