#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main (){
    int N;
    scanf("%d", &N);

    priority_queue<int, vector<int>, less<int>> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;

    while(N--){
        int n;
        scanf("%d", &n);
        if (pqMax.empty() || pqMax.size() == pqMin.size()){ // 무조건 최대 큐에 들어가야하는 경우
            pqMax.push(n);
        }
        else {
            pqMin.push(n);
        }

        if (!pqMax.empty() && !pqMin.empty()){
            if (pqMin.top() < pqMax.top()){ // 최대 큐는 항상 최소 작거나 같은 값을 가져야 한다. 
                int tempMax = pqMax.top();
                int tempMin = pqMin.top();
                pqMax.pop();
                pqMin.pop();

                pqMax.push(tempMin);
                pqMin.push(tempMax);
            }
        }
        printf("%d\n", pqMax.top());
    }
}
