#include <cstdio>

#define WEIGHT 0
#define VALUE 1

using namespace std;

int main()
{
    int dp[101][100001] = {0, };
    int item[101][2];

    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++){
        scanf("%d %d", &item[i][WEIGHT], &item[i][VALUE]);
    }

    for (int i = 1 ; i <= N ; i++){
        for (int w = 1 ; w <= K ; w++){ 
            if (item[i][WEIGHT] <= w){
                if ((item[i][VALUE] + dp[i-1][w-item[i][WEIGHT]]) > dp[i-1][w])
                    dp[i][w] = item[i][VALUE] + dp[i-1][w-item[i][WEIGHT]];
                else dp[i][w] = dp[i-1][w];
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    printf("%d", dp[N][K]);
    return 0;
}