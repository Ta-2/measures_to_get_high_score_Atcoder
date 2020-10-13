/**
 * ���ł��炻�̂������[�v����A
 * ������A�����񂾂烋�[�v���邩���܂����ׂāA
 * ���̂��ƁA k �ɑ΂���mod���ǂ��ɂ���邱�Ƃœ������o����Ƃ���
 * ���j�́A�����Ă���Œ��ɕ����񂾂��A�𓚎ʂ��Ă��������S��������Ȃ��i#^��^�j
 */

#include <iostream>
#include <vector>

int main(){
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    std::vector<int> s;
    std::vector<int> ord(n+1, -1);

    int c, l;
    int v = 1;

    while(ord[v] == -1){
        ord[v] = s.size();
        s.push_back(v);
        v = a[v - 1];
    }
    c = s.size() - ord[v];
    l = ord[v];

    if(k < l){
        std::cout << s[k] << std::endl;
    }
    else{
        k -= l;
        k %= c;
        std::cout << s[k + l] << std::endl;
    }

    return 0;
}