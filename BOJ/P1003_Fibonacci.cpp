#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> zeronecnt;

pair<int, int> getComb (int n){
    if (n == 0) return make_pair(0, 0);
    if (n == 1) return make_pair(1, 0);
    if (n == 2) return make_pair(1, 1);

    if (zeronecnt[n].first != -1) return zeronecnt[n];
    
    zeronecnt[n].first = getComb(n-1).first + getComb(n-2).first;
    zeronecnt[n].second = getComb(n-1).second + getComb(n-2).second;
    return zeronecnt[n];
}

int main (){
    int N;
    cin >> N;
    zeronecnt.resize(N+1, make_pair(-1, -1));

    getComb(N);

    cout << zeronecnt[N].first << " " << zeronecnt[N].second << endl;

    return 0;
}
