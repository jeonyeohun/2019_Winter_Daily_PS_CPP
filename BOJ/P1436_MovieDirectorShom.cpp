#include <iostream>
#include <string>

using namespace std;

int main (){
    int cnt = 0;
    int N;
    cin >> N;
    string num;
    for (int i = 0 ;; i++){
        num = to_string(i); // i를 0부터 1씩 올리면서 문자열로 바꾸기
        if(num.find("666") != string::npos) cnt++; // 문자열에서 666을 못찾으면 npos를 반환하니까 npos외에 다른게 아웃풋으로 나오면 cnt를 올린다.
        if (cnt == N) break; // cnt가 N에 도달하면 종료
    }
    cout << num << endl;
}