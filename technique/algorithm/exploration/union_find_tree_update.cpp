/*
 *  ABC117_D
 *  https://atcoder.jp/contests/abc177/tasks/abc177_d
 *
 *  -union_find_tree‚ÌÀ‘•(‰ü)-
 *
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
private:
	vector<int> Parent;
	vector<int> Rank;       //Œo˜Hˆ³k‚·‚é‚Ì‚ÅRank‚Ì—v‘f‚Í0‚©1‚É‚È‚é

public:
	UnionFind(int Num) : Parent(Num + 1), Rank(Num + 1, 0) {
		for(int i = 0; i < Num; ++i) {
			Parent[i] = i;
		}
	}

	int Root(int Node) {
		if(Parent[Node] == Node) return Node;
		else return Parent[Node] = Root(Parent[Node]);
	}

	void Unite(int U, int V) {
		U = Root(U);
		V = Root(V);
		if(U == V) return;

		if(Rank[U] < Rank[V]) Parent[U] = V;
		else {
			Parent[V] = U;
			if(Rank[U] == Rank[V]) ++Rank[U];
		}
	}

	bool Same(int U, int V) {
		return Root(U) == Root(V);
	}

};

int main() {
    int n, m;
	cin >> n >> m;
	UnionFind tree(n);
	for(int i = 0; i < m; ++i) {
        int a, b;
		cin >> a >> b;
        --a; --b;

		tree.Unite(a, b);
	}

	vector<int> num(n);     //Še–Ø‚Ìƒ‰ƒ“ƒN‚Ì‘å‚«‚³‚ğŠi”[(0‚æ‚è‘å‚«‚¢—v‘f‚ªª)
	for(int i = 0; i < n; ++i) ++num[tree.Root(i)];

	cout << *max_element(num.begin(), num.end()) << endl;

    return 0;
}