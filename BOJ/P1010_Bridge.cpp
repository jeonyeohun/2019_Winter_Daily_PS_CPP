#include <cstdio>

using namespace std;

int main (){
    int T, N, M;
    int dp[31][31];
    scanf("%d", &T);

    while(T--){
        scanf("%d %d", &N, &M);
        for (int i = 0 ; i <= M ; i++){
            dp[1][i] = i;
        }

        for (int i = 2 ; i <= N ; i++){
            for (int j = i ; j <= M ; j++){
                if (i == j) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
        }

        printf("%d\n", dp[N][M]);
    }
}