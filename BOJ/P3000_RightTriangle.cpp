#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int main (){
    ll N; 
    vector<ll> xcnt(100001, 0);
    vector<ll> ycnt(100001, 0);
    vector<ll> vx;
    vector<ll> vy;

    scanf("%lld", &N);

    for (int i = 0 ; i < N ; i++){
        ll x, y;
        scanf("%lld %lld", &x, &y);
        vx.push_back(x);
        vy.push_back(y);
        xcnt[x]++; // 각 좌표의 갯수 세기
        ycnt[y]++;
    }
    
    ll total = 0;
    for (int i = 0 ; i < N ; i++){
        ll sum = (xcnt[vx[i]]-1) * (ycnt[vy[i]]-1); // 한 좌표에 대해서 같은 x나 y를 공유하는 다른 좌표들의 갯수 찾기
        if (sum < 0) continue;
        total += sum;
    }
    
    printf("%lld", total);
    return 0;
}