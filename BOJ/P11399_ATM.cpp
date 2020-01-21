#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main (){
    int N;
    cin >> N;

    vector<int> mins;
    vector<long long> dp(1000);

    while(N--){
        int min;
        cin >> min;

        mins.push_back(min);
    }
    sort(mins.begin(), mins.end());
    long long answer;

    dp[0] = mins[0];
    for (int i = 1 ; i < mins.size() ; i++){
        dp[i] = mins[i]+dp[i-1];
    }

    cout << accumulate(dp.begin(), dp.end(), 0); 
    
}