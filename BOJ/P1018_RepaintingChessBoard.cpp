#include <iostream>
#include <vector>
using namespace std;


// 8*8 정답보드를 미리 만들어둔다.
char WB [8][8] = {
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
};

char BW [8][8] = {
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
};

int main (){
    int N, M;
    cin >> N >> M;
    vector<vector<char> > board(N, vector<char>(M, -1));
    for (int i = 0 ; i < N ; i++){
        string c;
        cin >> c;
        for (int j = 0 ; j < M ; j++){
            board[i][j] = c[j];
        }
    }
    
    int min = M*N; // 최악의 경우에는 모든 판을 다 바꿀 수도 있으니까 min의 최댓값을 M*N으로 설정
    
    for (int  i = 0 ; i <= N-8 ; i++){ // 8*8 윈도우를 몇번 움직여야 전체를 다 탐색할 수 있는지 찾기
       for (int j = 0 ; j <= M-8 ; j++){
           int cnt1 = 0; int cnt2 = 0;
           int final;
           for(int l = i ; l < i+8 ; l++){
               for (int k = j ; k < j+8 ; k+=1){
                   if (board[l][k] != WB[l-i][k-j]) cnt1++; // W로 시작하는 정답보드에 대해서 고쳐야하는 자리 수
                   if (board[l][k] != BW[l-i][k-j]) cnt2++; // B로 시작하는 정답보드에 대해서 고쳐야하는 자리 수
               }
           }
           (cnt1 < cnt2) ? final = cnt1 : final = cnt2; // 고쳐야하는 쪽이 더 작은 경우를 최종적으로 선택
           if (min > final) min = final; // 현재 최솟값보다 작으면 최솟값 바꾸기.
       }
   } 

    cout << min << endl;
    return 0;
}