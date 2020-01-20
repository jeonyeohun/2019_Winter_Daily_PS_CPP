#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>dp;

int main(){
    int k;
    cin >> k;
    dp.resize(k+1, 0);

    dp[1] = 0; // k가 1일 때, 1을 만들기 위한 최소 횟수는 0;

    for (int i =2 ; i <= k ; i++){ // 이제 가능한 조건을 다 시도해보고 제일 횟수가 적은 것을 dp[i] 로 정해주면 된다.
        dp[i] = dp[i-1]+1; // -1을 하는 조건은 모든 i에 대해 가능하기 때문에 일단 dp[i]에는 dp[i-1]+1 을 넣어준다.
        if (i%2 == 0) dp[i] = min(dp[i], dp[i/2]+1); // 2로 나누어 떨어진다면 2로 나누었을 때 횟수와 -1했을 때 횟수를 비교해서 더 작은 횟수로 업데이트
        if (i%3 == 0) dp[i] = min(dp[i], dp[i/3]+1); // 3으로 나누어 떨어지는 경우에도 더 작은 횟수로 업데이트
    }

    cout <<dp[k] << endl;
}