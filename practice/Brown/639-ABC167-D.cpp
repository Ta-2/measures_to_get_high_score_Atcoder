/**
 * 飛んでたらそのうちループする、
 * だから、何回飛んだらループするかをまず調べて、
 * そのあと、 k に対するmodをどうにか取ることで答えが出せるという
 * 方針は、解いている最中に浮かんだが、解答写しても実装が全く分からない（#^ω^）
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