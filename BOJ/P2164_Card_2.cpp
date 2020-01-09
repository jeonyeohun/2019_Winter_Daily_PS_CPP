#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    if (N<=2) { // 2 이하의 값은 그대로 출력하고 종료하면 된다.
        cout << N << endl;
        return 0;
    }
    
    int b = 1;
    for (int i = 0 ; ; i++){ 
        if ((b << i) > N) { // N보다 커질 때 까지 2^n 을 계속 취해서 범위찾기
            b = b << i;
            break;
        }
    }
    
    int result = 0;
    int bn = N%(b/2); // 범위 내에서 몇번째에 위치한 수인지 찾기
    if (bn == 0) result = b/2; // 딱 나누어 떨어지면 범위 내의 마지막 수이므로 b/2를 결과로 지정
    else
        for (int i = 0 ; i < bn ; i++) result += 2; // bn 번째 짝수를 만든다.
    
    cout << result;
}
