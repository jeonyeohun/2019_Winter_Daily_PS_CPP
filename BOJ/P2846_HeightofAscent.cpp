#include <cstdio>
#include <vector>

using namespace std;

int main (){
    vector <int> v;
    int N, h, j=0;
    int maxh = 0, i = 0, start  = 0;
    scanf("%d", &N);

    for (int k = 0 ; k < N ; k++){
        int p;
        scanf("%d", &p);
        v.push_back(p); 
    }

    while(true){
        if (v[i] < v[i+1]) i++; // 다음 숫자가 더 크면 그냥 이동 = 오르막길
        else { // 내리막길에 들어서면
            int h = v[i] - v[start]; // 출발점-현재지점으로 높이를 구한다.
            if (maxh < h) maxh = h; // 최대높이 구하기
            start = i+1; // 다시 탐색을 시작하는 시작점 잡아주기
            i++; // 한칸 옆으로 이동 
        }
        if (i == N) break; 
    }

    printf("%d", maxh);
    return 0;
}