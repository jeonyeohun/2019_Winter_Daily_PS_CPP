#include <iostream>

using namespace std;

typedef long long ll;

// 고정비용 a, 가변비용 b, 가격 c

int main (){
    ll a, b, c;
    cin >> a >> b >> c;
    
    // 손익 분기점이 존재하지 않는 조건 
    if (c == 0 || (c-b) <= 0 || a/(c-b)+1 == 0) cout << -1 << endl; 
    else cout << a/(c-b)+1 << endl;
    

    return 0;
}