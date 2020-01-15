#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> board (9, vector<int>(9));
vector<pair<int, int>> cand;
vector<vector<vector<int>>> sol;

bool isPossible(int row, int col, int n){
    for (int i = 0 ; i < board.size() ; i++){
        if ((i!=row) && (board[i][col] == n)) return false;
        if ((i!=col) && (board[row][i] == n)) return false;
    }
    int y = row/3, x = col/3;
    for (int i = y*3 ; i < y*3+3 ; i++){
        for (int j = x*3 ; j < x*3+3 ; j++){
            if ((i!=row&&j!=col) && board[i][j] == n) return false;
        }
    }
    return true;
}

void solution (int row, int col, int cnt){
    if (cnt == cand.size()) {
        if (isPossible(cand[cnt-1].first, cand[cnt-1].second, board[cand[cnt-1].first][cand[cnt-1].second])){
            sol.push_back(board);
        }
        return;
    }
    for (int i = 1 ; i <= 9 ; i++){
        if(isPossible(row, col, i)){
            board[row][col] = i;
            solution(cand[cnt+1].first, cand[cnt+1].second, cnt+1);
            board[row][col] = 0;
        }
    }
}

int main (){
    for (int i = 0 ; i < board.size() ; i++){
        for (int j = 0 ; j < board.size() ; j++){
            cin >> board[i][j];
            if (board[i][j] == 0) cand.push_back(make_pair(i, j));
        }
    }

    solution(cand[0].first, cand[0].second, 0);
    
    for (auto v : sol[0]){
        for (auto i : v){
            cout << i << " ";
        }
        cout << "\n";
    }

    

}
