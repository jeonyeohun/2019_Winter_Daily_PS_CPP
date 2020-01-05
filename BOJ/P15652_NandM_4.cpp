#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<int> numbers (9, 0);

void DFS (int cnt){
    if (cnt == M){
        for (int i = 1 ; i < M ; i++){
            if (numbers[i-1] > numbers[i]) return; // 비내림차순이 아니면 그냥 리턴
        }
        for (int i = 0 ; i < M ; i++){ // 여기까지 왔으면 비 내림차순이니까 numbers에 들어있는거 출력
            cout << numbers[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1 ; i <= N ; i++){
        numbers[cnt] = i;
        DFS(cnt+1);
    }
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    DFS(0);

    return 0;
}