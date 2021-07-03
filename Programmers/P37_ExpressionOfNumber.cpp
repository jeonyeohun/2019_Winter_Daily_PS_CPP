#include <string>
#include <vector>
#include <iostream>

using namespace std;

int calcSum(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += i;
    }

    return sum;
}

int solution(int n) {
    int answer = 0;
    int start = 1, end = 1;

    while (start <= n) {
        int result = calcSum(start, end);
        if (result == n) answer++;
        if (result < n) {
            end++;
        }
        else {
            start++;
        }
    }


    return answer;
}