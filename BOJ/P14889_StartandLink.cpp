#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

vector<int> start;
vector<int> link;
vector<bool> visited;
int N;
int ans_min = INT_MAX;

void back_tracking (vector<vector<int>> board){
    if (start.size() == N/2){ // 스타트 팀
        int start_score = 0;
        int link_score = 0;
        
        for (int i = 1 ; i <= N ; i++) if (!visited[i]) link.push_back(i); // 링크 팀 만들기
        
        for (int i = 0 ; i < N/2 ; i++){ // 각팀의 ij 조합의 합
            for (int j = i+1 ; j < N/2 ; j++){
                if (i==j) continue;
                start_score += (board[start[i]][start[j]] + board[start[j]][start[i]]);
                link_score += (board[link[i]][link[j]] + board[link[j]][link[i]]);
            }
        }
        
        int diff = abs(start_score-link_score);
        if (diff < ans_min) ans_min = diff;
        
        link.clear();
        return;
    }

    for (int i = 1 ; i <= N ; i++){
        if(!visited[i]){
            visited[i] = true;
            start.push_back(i);
            back_tracking(board);
            start.pop_back();
            visited[i] = false;
        }
    }
}

int main (){
    cin >> N;
    vector<vector<int>> board(N+1, vector<int>(N+1, 0));
    for (int i = 1 ; i <= N ; i++){
        for (int j = 1 ; j <= N ; j++){
            int n; cin >> n;
            board[i][j] = n;
        }
    }
    visited.resize(N+1, false);
    back_tracking(board);

    cout << ans_min;

    return 0;
}
