#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int P[1001];
int memo[1001];

void solution (int n){
    memo[0] = 0;
    memo[1] = P[1];
    for (int i = 2 ; i <= n ; i++){
        for (int j = 1 ; j <=i ; j++){
            memo[i] = max(memo[i], memo[i-j]+P[j]);
        }
    }
}

int main (){
    int N;
    cin >> N;
    int t = N;

    for (int i = 1 ; i<=N ; i++){
        int in;
        cin >> in;
        P[i] = in;
    }
    
    solution(t);
    cout << memo[t];
    return 0;
}
