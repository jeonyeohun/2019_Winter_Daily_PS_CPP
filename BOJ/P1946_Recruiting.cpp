#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int T;
    scanf("%d", &T);

    while(T--){
        int N;
        int cnt = 0;
        scanf("%d", &N);
        
        vector<pair<int, int>> people;
        
        while(N--){ // <서류접수, 면접점수> pair 로 입력
            int paper, interview;
            scanf("%d %d", &paper, &interview);
            people.push_back({paper, interview});
        }

        sort(people.begin(), people.end()); // first 기준으로 오름차순 정렬을 수행하면 서류 1등이 가려짐. 서류 1등은 무조건 채용한다.

        int best = people[0].second; // 서류 1등의 면접 등수 기록. 이 등수보다 높은 등수인 사람들만 채용 대상이 됨
        cnt++;

        for (int i = 1 ; i < people.size() ; i++){
            if (people[i].second < best){
                best = people[i].second; // 면접 등수의 제한을 계속 갱신하면서 채용 대상을 걸러낸다.
                cnt++;
            }
        }

        printf("%d\n", cnt);
    }
}