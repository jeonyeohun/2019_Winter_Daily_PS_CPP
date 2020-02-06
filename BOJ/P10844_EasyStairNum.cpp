#include <iostream>
#include <vector>
#include <numeric>

#define mod 1000000000

using namespace std;

int main (){
    int N;
    cin >> N; 

    vector<vector<long long>> dp (N, vector<long long>(10, 1));

    for (int i = 1 ; i < N ; i++){
        for (int j = 0 ; j < 10 ; j++){
            if (j==0) dp[i][j] = (dp[i-1][j+1] % mod); // 0을 만들 수 있는 수는 1 밖에 없으므로 1에 대한 갯수만 더해준다.
            else if (j==9) dp[i][j] = (dp[i-1][j-1] % mod); // 9를 만들 수 있는 수는 8 밖에 없으므로 8에 대한 갯수만 더해준다.
            else  dp[i][j] = (dp[i-1][j-1] % mod + dp[i-1][j+1] % mod); // 0과 9가 아닌 나머지 수들은 모두 j-1, j+1 로 만들 수 있다.
        }
    }

    long long ans = 0;
    for(int i = 0 ; i < 9 ; i++){
        ans = (ans + dp[N-1][i])%mod;
    }
    cout << ans;
}