#include <iostream>
using namespace std;

int main (){
    int i = 0;
    int h, w, n;
    int t;
    
    cin >> t;
    int answer [t]; // 테스트케이스 갯수만큼 배열 만들기 결과값 저장하는 용도.

    for (int i = 0 ; i < t ; i++){
        cin >> h >> w >> n; // 입력
        int ch, ho;

        // 0으로 나누어 떨어지면 꼭대기 층이니까 호수는 높이만큼이고 층수는 n/h
        if (n%h==0) {
            ho = n/h;
            ch = h;
        }

        // 딱 안떨어지면 호수가 몫+1, 층수는 방문객을 높이로 나눈 나머지
        else {
            ho = n/h+1;
            ch = n%h;
        }

        answer[i] = ch*100 + ho; // 층에 100 곱하고 호수 더해서 최종 결과 만들기
    }

    for (int i = 0 ; i < t ; i ++){
        cout << answer[i] << endl;
    }

    return 0;
}