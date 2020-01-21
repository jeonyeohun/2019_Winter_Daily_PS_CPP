#include <iostream>
#include <vector>

using namespace std;

int main (){
    int N;
    cin >> N;
    
    vector<int> coins = {7, 5, 2, 1};

    int total = 0;

    for (auto coin : coins){
        total += N/coin;
        N %= coin;
    }

    cout << total;

    return 0;
}