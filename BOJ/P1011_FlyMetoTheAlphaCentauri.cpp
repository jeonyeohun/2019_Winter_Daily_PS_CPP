#include <iostream>
#include <cmath>
using namespace std;

int main (){
    int t;
    cin >> t;

    while(t--){
        int x, y;
        cin >> x >> y;

        int d = y-x; // 이동해야하는 거리 구하기

        long long jump = 1;
        for(;;jump++){
            if(jump*jump > d) break; // 점프하는 최고속도 구하기
        }
        jump--;
        
        long long left = d - (jump * jump); // 규칙대로 최대한 이동하고 남은 거리

        left = (long long)ceil((double)left / (double)jump); // 남은거리를 최고속도로 나누고 올림하면 더 가야하는 거리가 나온다.

        cout << jump * 2 -1 + left << endl;
    }
    return 0;

}