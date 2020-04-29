#include<cstdio>
#include <iostream>

using namespace std;

int main (){
    int T;
    scanf("%d", &T);

    while(T--){
        int n;
        scanf("%d", &n);
        int arr[2][n];
        int dp [2][n];
        
        for (int i = 0 ; i < 2 ; i++){
            for (int j = 0 ; j < n ; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = arr[1][0] + arr[0][1];
        dp[1][1] = arr[0][0] + arr[1][1]; 

        for (int i = 2 ; i < n ; i++){
            dp[0][i] = max(max(dp[0][i-2], dp[1][i-2]) , dp[1][i-1]) + arr[0][i];
            dp[1][i] = max(max(dp[1][i-2], dp[0][i-2]), dp[0][i-1]) + arr[1][i];
        }


        printf("%\nd", max(dp[0][n-1], dp[1][n-1]));
    }
}