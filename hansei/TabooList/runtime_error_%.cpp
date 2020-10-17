int main(){
	int a = 1;
	//単純にこうしてはいけない
	a = a % 0;
	
	//こんな時に気づきにくいので注意！！
	for(int i = 0;i < 10; i++)a += (a % i);
	
	return 0;
}