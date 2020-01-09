#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    if (x < 11) return true;
    
    int x_copy = x;
    int sum = 0;
    
    while(x_copy>0){
        sum += x_copy%10;
        x_copy /= 10;
    }
    
    if (x%sum != 0) answer = false;
    return answer;
}