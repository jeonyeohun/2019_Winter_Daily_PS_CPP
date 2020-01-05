#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int> > result;
vector<bool> visited(9, false);
vector<int> numbers(9, 0);

void DFS(int cnt){
    if(cnt == M){
        bool isAscending = true;
        vector<int> temp;

        for (int i = 1 ; i < M ; i++){
            if (numbers[i]-numbers[i-1]<0){ // 오름차순이 아닌 값이 있으면 플래그 함수 false 로 변경
                isAscending = false;
            }
        }
        if (isAscending){ // true일때만 결과 벡터에 넣어주기. 사실 벡터에 안넣고 출력시키기만 해도 된다.
            temp.assign(numbers.begin(), numbers.begin()+M);
            result.push_back(temp);
        }
        return;
    }

    for (int i = 1 ; i <= N ; i++){
        if(!visited[i]){
            visited[i] = true;
            numbers[cnt] = i;
            DFS(cnt+1);
            visited[i] = false; 
        }
    }
}


int main (){
    cin >> N >> M;
    
    DFS(0);

    for (vector<int> v : result){
        for (int i : v){
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}