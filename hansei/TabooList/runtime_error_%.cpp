int main(){
	int a = 1;
	//�P���ɂ������Ă͂����Ȃ�
	a = a % 0;
	
	//����Ȏ��ɋC�Â��ɂ����̂Œ��ӁI�I
	for(int i = 0;i < 10; i++)a += (a % i);
	
	return 0;
}