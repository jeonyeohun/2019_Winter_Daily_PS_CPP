#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<int> frt (30);

int DFS(int pos, int cnt){
    if (cnt == M-N){
        vector<int> temp;
        return 1;
    }
    int ret = 0;
    for (int i = pos  ; i < N ; i++){
        frt[cnt] = i;
        ret += DFS(i, cnt+1);
    }
    return ret;
}

int main (){
    cin >> N >> M;
    
    int result = DFS(0, 0);
    
    cout << result;
    return 0;
}
