#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int changeAlpha (int cur, string &init, char c);

int main(){
    string name;
    int t; cin >> t;
    bool rightdir = true;

    while(t--){
        cin >> name;
        string init(name.size(), 'A');
        int cnt = 0;
        int cur = 0;

        while(name.compare(init) != 0){
            if(name[cur] != 'A') cnt+=changeAlpha(cur, init, name[cur]);
            cnt += getDist(name, cur)-1;
            cur += getDist(name, cur)-1;
            name[cur]
        }
    }

    return 0;
}

int getDist(string& name, int cur){
    int rcur = cur;
    int lcur = cur;
    int rcnt = 0;
    int lcnt = 0;
    while(name[rcur] != 'A'){
        if (lcur == name.size()-1){
            lcur = 0;
            continue;
        }
        rcur++;
        rcnt++;
    }
    while(name[lcur] != 'A'){
        if (lcur == 0){
            lcur = name.size()-1;
            continue;
        }
        lcur--;
        lcnt++;
    }
    if (rcnt >= lcnt) return rcnt;
    else return lcnt * -1;
}

int changeAlpha (int cur, string& init, char c){
    int cnt = 0;
    char a = 'A';
    char b = 'Z';
    if(abs('A' - c) <= abs('Z' - c)+1){
        while(a != c){
            cnt++;
            a+=1;
        }
        init[cur] = a;
    }
    else{
        cnt++;
        while(b != c){
            cnt++;
            b-=1;
        }
        init[cur] = b;
    }
    return cnt;
}
