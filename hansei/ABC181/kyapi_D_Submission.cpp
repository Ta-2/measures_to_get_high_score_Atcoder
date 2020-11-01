#include <iostream>
#include <vector>
#include <string>
using namespace std;

int CtoI(char c) {
    return c - '0';
}

int main() {

    string s;
    cin >> s;
    vector<int> num(10);
    for(auto &e: s) {
        ++num[CtoI(e)];
    }

    auto judge1 = [&](int a, int b)->bool{return s.size()==2&&num[a]==1&&num[b]==1;};
    auto judge2 = [&](int a, int b)->bool{return s.size()>=3&&num[a]>=1&&num[b]>=1;};

    if(s.size()==1&&num[8]==1) {
        cout << "Yes" << endl;
        return 0;
    }
    if(s.size()==2&&num[8]==2) {
        cout << "Yes" << endl;
        return 0;
    }
    if(judge1(1,6)||judge1(2,4)||judge1(3,2)||judge1(4,8)||judge1(5,6)||
        judge1(6,4)||judge1(7,2)||judge1(9,6)) {
            cout << "Yes" << endl;
            return 0;
        }
/***************************************/
    if(judge2(1,2)) {
        if(num[1]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 1; i <= 9; i+=2) {
            if(i == 1) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    if(judge2(2,8)) {
        for(int i = 1; i <= 9; i+=2) {
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    if(judge2(6,8)) {
        for(int i = 1; i <= 9; i+=2) {
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if(judge2(8,4)) {
        for(int i = 1; i <= 9; i+=2) {
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    if(judge2(3,6)) {
        if(num[3]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 1; i <= 9; i+=2) {
            if(i == 3) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if(judge2(7,6)) {
        if(num[7]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 1; i <= 9; i+=2) {
            if(i == 7) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if(judge2(9,2)) {
        if(num[9]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 1; i <= 9; i+=2) {
            if(i == 9) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    if(s.size()>=3&&num[4]>=2) {
        for(int i = 1; i <= 9; i+=2) {
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    if(judge2(5,2)) {
        if(num[5]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 1; i <= 9; i+=2) {
            if(i == 5) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

/*****************************************/
    if(judge2(1,6)) {
        if(num[6]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 2; i <= 8; i+=2) {
            if(i == 6) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if(judge2(4,8)) {
        if(num[4]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        if(num[8]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 2; i <= 8; i+=2) {
            if(i == 4 || i == 8) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if(judge2(2,4)) {
        if(num[2]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        if(num[4]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 2; i <= 8; i+=2) {
            if(i == 2||i == 4) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if(s.size() >= 3 && num[8]>=2) {
        if(num[8]>=3) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 2; i <= 8; i+=2) {
            if(i == 8) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if(judge2(3,2)) {
        if(num[2]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 2; i <= 8; i+=2) {
            if(i == 2) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if(judge2(9,6)) {
        if(num[6]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 2; i <= 8; i+=2) {
            if(i == 6) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if(judge2(5,6)) {
        if(num[6]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 2; i <= 8; i+=2) {
            if(i == 6) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if(judge2(7,2)) {
        if(num[2]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 2; i <= 8; i+=2) {
            if(i == 2) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if(judge2(6,4)) {
        if(num[6]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        if(num[4]>=2) {
            cout << "Yes" << endl;
            return 0;
        }
        for(int i = 2; i <= 8; i+=2) {
            if(i == 6||i == 4) continue;
            if(num[i]>=1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}