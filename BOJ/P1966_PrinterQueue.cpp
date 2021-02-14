#include <cstdio>
#include <deque>

using namespace std;

int main (){
    int T, N, M;
    scanf("%d", &T);
    
    while(T--){
        deque<pair<int, int>> dq;
        scanf("%d %d", &N, &M);
        
        for (int i = 0 ; i < N ; i++){
            int val;
            scanf("%d", &val);
            dq.push_back(make_pair(i, val));
        }
        
        int count = 0;
        while(!dq.empty()){
            auto turn = dq.front();
            for (int i = 1 ; i < dq.size() ; i++){
                if (dq[i].second > turn.second){
                    dq.push_back(dq.front());
                    dq.pop_front();
                    break;
                }
            }
            if(dq.front().first == turn.first){
                count++;
                if (dq.front().first == M) {
                    printf("%d\n", count);
                    break;
                }
                dq.pop_front();
            }
        }
    }
}
