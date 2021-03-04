#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<bool> primes;

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    primes.resize(N+1, true);
    
    primes[1] = false;
    for (int i = 2 ; i <= sqrt(N) ; i++){
        for (int j = i + i ; j <= N ; j += i){
            primes[j] = false;
        }
    }

    int answer = 0;
    if(primes[N]) answer++;
    
    for (int i = 2 ; i < primes.size() ; i++){
        if(!primes[i]) continue;
        int sum = i;

        for (int j = i + 1 ; j < primes.size() ; j++){
            if (primes[j] == true) {
                sum += j;
                if (sum == N) answer++;
                if (sum >= N) break;
            }
        }
    }
    
    cout << answer;
}
