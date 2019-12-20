#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void maxswap(int& a, int& b, int& c); // 제일 길이가 큰 변을 빗변 c로 만들기 
bool isRight(int& a, int& b, int& c); // 직각삼각형 판별

int main(){
    vector<bool> ans; // 정답 저장하기
    int a, b, c;

    while(1){
        cin >> a >> b >> c;
        if (a+b+c == 0) break; // 길이라서 어차피 음수는 안나오니까 다 더해서 0이면 끝내버리자
        maxswap(a, b, c); // 제일 길이가 긴 변을 빗변으로 만들기
        ans.push_back(isRight(a, b, c)); // 직각삼각형 판정해서 결과 저장
    }

    for(bool a : ans){ // 하나씩 꺼내면서 결과 출력하기
        if (a) cout << "right" << endl;
        else cout << "wrong" << endl;
    }
}

bool isRight(int& a, int& b, int& c){
    if (pow(a, 2)+pow(b, 2) == pow(c, 2)) return true; // 직각삼각형 판별식 a^2+b^2=c^2
    else return false;
}

void maxswap (int& a, int& b, int& c){ // 제일 긴 애를 c로 만들자
    if (a > c){
        int temp = c;
        c = a;
        a = temp;
    }
    if (b > c){
        int temp = c;
        c = b;
        b = temp;
    }
}