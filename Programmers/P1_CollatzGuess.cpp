#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    while(num != 1 && answer <= 500){
        (num % 2 == 1) ? (num = num * 3 + 1) : (num /= 2);
        answer++;
    }
    if (answer > 500) answer = -1;
    return answer;
}