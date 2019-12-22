#include <iostream>
#include <cmath>

using namespace std;

int isIntersect (int r1, int r2, double d);
int main (){
    int x1, x2, y1, y2, r1, r2;
    int t = 0;

    cin >> t;

    while(t--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2; // 입력받기
        if (x1 == x2 && y1 == y2 && r1 == r2) { // 두 점이 같은 좌표이고 반지름도 같다면 동일한 원. -1 을 출력하고 끝내기
            cout << -1 << endl;
            continue;
        }
        double d = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)); // 두 점 사이의 거리 구하기
        cout << isIntersect(r1, r2, d) << endl; // 교차점 개수 판정함수 호출 및 출력
    }
    return 0;
}

int isIntersect (int r1, int r2, double d){
    if (r1 + r2 < d || abs(r1 - r2) > d || d == 0) return 0; // 두 원이 만나지 않을 때
    if (r1 + r2 == d || abs(r1 - r2) == d) return 1; // 두 원이 만나는 점이 하나일 때
    if (abs(r1 - r2) < d && r1 + r2 > d) return 2; // 두 원이 만나는 점이 두개일 때
    else return -1;
}