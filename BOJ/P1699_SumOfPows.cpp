#include <cstdio>
#include <algorithm>

using namespace std;

int dp[100001] = {0};

int main (){
    int N;
    scanf("%d", &N);

    for (int i = 1 ; i <= N ; i++){
        dp[i] = i;
        for (int j = 1 ; j*j <= i ; j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }

    printf("%d\n", dp[N]);
}