#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> board(15, vector<bool>(15, false));
vector<pair<int, int>> result;

bool inRange (int row, int col, int x, int y, int N){
    if (row+y >= N || row+y < 0 || col+x >= N || col+x < 0) return false;
    return true;
}

bool isPossible(int row, int col, int N){
    if (row == 0) return true;
    
    // 위쪽 직선 /
    int y = -1;
    while(inRange(row, col, 0, y, N)){
        if (board.at(row+y)[col] == true) return false;
        y--;
    }

    //  왼쪽 대각선 //
    int x = -1;
    y = -1;
    while(inRange(row, col, x, y, N)){
        if (board.at(row+y)[col+x] == true) return false;
        y--; x--;
    }
    
    // 오른쪽 대각선 // 
    x = 1, y = -1;
    while(inRange(row, col, x, y, N)){
        if (board.at(row+y)[col+x] == true) return false;
        y--; x++;
    }

    return true;
}

int back_tracking(int N, int row){
    
    if (result.size() == N){
        return 1;     
    }

    int ret = 0;
    for (int i = 0 ; i <board.size()  ; i++){
        if (isPossible(row, i, N)){
            board[row][i] = true;
            result.push_back(make_pair(row, i));
            ret += back_tracking(N, row+1);
            result.pop_back();
            board[row][i] = false;
        }
    }
    return ret;
}
int main (){
    int N;
    cin >> N; 

    board.resize(N);
    cout << back_tracking(N, 0);
    
    return 0;
}
