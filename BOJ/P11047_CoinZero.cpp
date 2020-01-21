#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main (){
    int N, K;
    cin >> N >> K;
    
    vector<int> coins(N);

    for (int i = 0 ; i < N ; i++){
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end(), greater<int>());
    int total = 0;

    for (auto coin : coins){
        total += K/coin;
        K %= coin;
    }

    cout << total;

    return 0;
}