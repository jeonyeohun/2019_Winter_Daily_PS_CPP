#include <iostream>
#include <vector>

using namespace std;

int main (){
    int N;

    cin >> N;
    vector<int> stairs (N);
    vector<vector<int>> dp (N, vector<int>(2, 0));

    for (int i = 0 ; i < N ; i++){
        cin >> stairs[i];
    }

    if (N == 1) {
        cout <<  stairs[0];
        return 0;
    }

    dp[0][0] = stairs[0]; // 첫 계단
    dp[1][0] = stairs[1]; // 바로 두번째 계단을 밟는 경우
    dp[1][1] = stairs[0] + stairs[1]; // 첫계단을 밟고 연달아 두번째 계단을 밟는 경우

    for (int i = 2 ; i < N ; i++){
        dp[i][0] = max(dp[i-2][0], dp[i-2][1])+stairs[i]; // 한칸 건너뛰어서 밟기
        dp[i][1] = dp[i-1][0] + stairs[i]; // 연달아 밟기. dp[i-1][1] 은 세개의 계단을 연달아 밟는거니까 제외해야됨
    }
    cout << max(dp[N-1][0], dp[N-1][1]);
}