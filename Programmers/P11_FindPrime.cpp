#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

#define MAX 9999999 

bool visited[MAX];
bool isUsed[MAX] = { 0, };
string comb;
int count = 0;

void dfs(int size, vector<bool> primes, string numbers) {
    if (!comb.empty() && comb.size() <= size) {
        int num = stoi(comb);
        if (!isUsed[num] && primes[num]) {
            cout << comb << endl;
            isUsed[num] = true;
            count++;
        }
        if (comb.size() == size) return;
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            comb.push_back(numbers[i]);
            dfs(size, primes, numbers);
            comb.pop_back();
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;

    vector<bool> primes(MAX, true);

    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i <= sqrt(MAX); i++) {
        for (int j = i + i; j <= MAX; j += i) {
            primes[j] = false;
        }
    }

    dfs(numbers.size(), primes, numbers);

    return count;
}