#include <iostream>
#include <vector>

using namespace std;

int main (){

    int N;
    cin >> N; 
    vector<vector<int>> triangle (N, vector<int>(N, -1));
    vector<vector<int>> dp (N, vector<int>(N, 0));

    for(int i = 1 ; i <= N ; i++){
        for (int j = 0 ; j < i ; j++){
            cin >> triangle[i-1][j];
        }
    }

    for (int i = 1 ; i <= N ; i++){
        for (int j = 0 ; j < i ; j++){
            if (i == 1) dp[i-1][j] = triangle[i-1][j];
            else if (j == 0) dp[i-1][j] = dp[i-2][j] + triangle[i-1][j];
            else if (j == i-1) dp[i-1][j] = dp[i-2][j-1] + triangle[i-1][j];
            else{
                dp[i-1][j] = max(dp[i-2][j-1]+triangle[i-1][j], dp[i-2][j]+triangle[i-1][j]);
            }
        }
    }

    int max_score = 0;
    for (int i = 0 ; i < N ; i++){
        max_score = max(dp[N-1][i], max_score);
    }

    cout << max_score;
    return 0;
    
}