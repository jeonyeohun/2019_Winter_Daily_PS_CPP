#include<iostream>
#include<vector>

using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> inarr;
    vector<int> outarr;
    vector<int> cntarr (0, N);
    
    while(N--){
        int n;
        cin >> n;
        inarr.push_back(n);
    }

    for (int i = 0 ; i < inarr.size() ; i++){
        cntarr[inarr[i]-1]++;
    }

    for (int i = 1 ; i < cntarr.size() ; i++){
        cntarr[i]+=cntarr[i-1];
    }

    for (int i = inarr.size()-1 ; i >= 0 ; i++){
        outarr[cntarr[inarr[i]-1]-1] = inarr[i];
    }

    for (int s : outarr){
        cout << s << "\n";
    }
}