#include <iostream>
#include <vector>
using namespace std;

struct Collection{
	vector<int>member;	//取り扱う要素の配列(0～要素数-1までの間で集合の操作を行う)
						//(※要するに要素として(要素数、要素数+1、...)の数字は扱えない)
	
	Collection(int N){
		member = vector<int>(N, -1);	//要素数をコンストラクタで設定する
		//このとき、各要素はそれぞれ要素数1の集合として扱われている
	}
	
	int root(int i){
		//指定された要素が属している集合の最大値要素を探す
		//(集合の要素数はマイナスで表されていて、各要素は正の数と決めているので
		//判別と集合の要素数のカウントを同時にこなしている。考えた人天才)
		return (member[i] >= 0 ? root(member[i]): i);
	}
	
	bool conbine(int a, int b){
		int x = root(a);
		int y = root(b);
		//aとbが同じ集合に所属しているとき、root(a)とroot(b)は一致する
		//つまり、同じ集合に属しているかの問題は、
		//それぞれの集合の最大値要素が等しいかの問題と同値であると言うこと(考えた人マジ天才)
		if(x == y)return false;
		//違っていた場合、x < yの関係に調整し、
		if(x > y)swap(x, y);
		//集合の要素数を、member[y]の方に加算
		member[y] += member[x];
		//member[x]からyへと集合を結合している
		member[x] = y ;
		
		return true;
	}
	
	int total(int i){
		//集合の要素数は、-member[集合の最大値要素]と成っているので-を掛けてreturnすれば良い
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
