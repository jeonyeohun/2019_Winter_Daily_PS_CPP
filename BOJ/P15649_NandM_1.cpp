#include <iostream>
#include <vector>

using namespace std;
vector<bool> visited(9, false);
vector<int> numbers(9, 0);
int N, M;

void DFS(int cnt){
    if (cnt == M){ // 배열에 값이 4개가 쌓이면 출력하고 종료
        for (int i = 0 ; i < M ; i++){
            cout << numbers[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1 ; i <= N ; i++){ // 자기 자신을 제외한 다른 노드들에 방문한 적이 있는지 확인 
        if(!visited[i]){ // 처음 방문하는 노드를 만나면
            visited[i] = true; // 방문했다고 마킹하고 
            numbers[cnt] = i; // 배열 0번째의 값 넣기
            DFS(cnt+1); // 다음 배열에 넣을 값 찾기 재귀호출
            visited[i] = false; // 여기에 왔다는건 cnt+1번째 배열에 값이 들어있는채로 리턴된거니까 다시 false로 만들어줘야 다음번 수열을 찾을 때 사용할 수 있다.
        }
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    DFS(0);

    return 0;
}