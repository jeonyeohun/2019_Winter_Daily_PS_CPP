#include <cstdio>
#include <vector>

using namespace std;

int main (){
    int N, K;
    int cnt = 0;
    scanf("%d %d", &N, &K);

    vector<bool> arr(N+1, false) ;

    for (int i = 2 ; i <= N ; i++){
        if (arr[i] == false){
            for (int j = i ; j <= N ; j+=i){
                if (arr[j] == false){
                    arr[j] = true;
                    cnt++;
                }
                if (cnt == K){
                    printf("%d\n", j);
                    return 0;
                }
            }
        }
    }
}
