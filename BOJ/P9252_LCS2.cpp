#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define LEFT 1
#define TOP 2
#define TOPLEFT 3

int dp[1001][1001];
int substr [1001][1001];

void print_lcs(int (*b)[1001], string X, int i, int j){
    if (i == 0 || j == 0) return ;

    if (b[i][j] == TOPLEFT){
        print_lcs(b, X, i-1, j-1);
        cout << X[j-1];
    }
    else if (b[i][j] == TOP){
        print_lcs(b, X, i-1, j);
    }
    else if (b[i][j] == LEFT){
        print_lcs(b, X, i, j-1);
    }

    return;
}

int main()
{
    string s1, s2;

    cin >> s1 >> s2;
    int lcs = 0;

    for (int i = 1; i <= s2.size(); i++) // s2 문자열 하나 당 s1의 문자열의 문자들을 모두 비교해보자.
    {
        for (int j = 1; j <= s1.size(); j++)
        {
            if (s2[i - 1] == s1[j - 1])  // 두 문자가 같으면
            {
                dp[i][j] = dp[i - 1][j - 1] + 1; // 대각선 위의 값 + 1 -> 바로 이전 상황에서 최대 값이 저장되어 있는 위치이다.
                substr[i][j] = TOPLEFT; // 그동안 왔던 길 마킹 -> 대각선 위에서 값을 가져왔기 때문에 대각선 위로 마킹
                lcs = max(lcs, dp[i][j]);
            }
            else
            {
                if (dp[i - 1][j] >= dp[i][j - 1]) {  // s1에서 하나를 제외했을 때가 더 좋은 선택일 경우 
                    dp[i][j] = dp[i - 1][j]; // 바로 위에서 값을 가져온다.
                    substr[i][j] = TOP;
                }
                else{
                    dp[i][j] = dp[i][j - 1]; // s2에서 하나를 제외했을 때가 더 좋은 선택일 경우에는 왼쪽에서 값을 가져온다.
                    substr [i][j] = LEFT;
                }
            }
        }
    }

    cout << lcs << endl;
    for (int i = 0 ; i <= s2.size() ; i++){
        for (int j = 0 ; j <= s1.size() ; j++){
            if (dp[i][j] == lcs) {
                print_lcs(substr, s1, i, j);
                return 0;
            }
        }
    }

    return 0;
}