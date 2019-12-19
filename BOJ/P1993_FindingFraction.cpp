#include <iostream>

using namespace std;

int main(){
    int N, den = 1, num = 1; // 분모, 분자 1, 1로 초기화 
    int j = 0, i = 1, sum = 0;
    cin >> N;

    while(1){
        for (j = 0 ; j < i ; j++){
            if (sum + j+1 == N){ // 총 계산 횟수가 N만큼 되면 종료. j+1을 해주는건 j가 0부터 시작하기 때문에 하나 올려줘야 제대로 카운트 된다.
            cout << num << "/" << den << endl; // 결과 출력하고 끝내기
            return 0;
        } 
            if (i%2!=0){ // 홀수 열에서는 분모+1 분자-1
                den+=1;
                num-=1;
            }
            else{ // 짝수 열에서는 분모-1, 분자+1 
                den-=1;
                num+=1;
            }
            if (den<1) den = 1; // 맨끝에 도달하면 안빼고 그대로 유지하니까 0이되면 다시 1로 돌려놓자
            if (num<1) num = 1;
        }
        sum += j; // 현재까지 연산갯수를 누적하고
        i++; // 다음 열로 이동
    }

    
    return 0;
}