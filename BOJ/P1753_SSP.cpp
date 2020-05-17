#include <cstdio>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int v, e;
vector <vector<pair<int, int>>> graph (20001);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dist [20001];

void initSP(){
    for (int i = 1 ; i <= v ; i ++){
        dist[i] = INF;
    }
}

void setStart(int start){
    pq.push(make_pair(0, start));
    dist[start] = 0;
}

void daijkstra(){
    while(!pq.empty()){
        pair<int, int> node = pq.top();
        pq.pop();

        int cost_here = node.first; // 현재 노드의 최단거리
        int here = node.second;     // 현재 노드의 위치

        for (int i = 0 ; i < graph[here].size() ; i++){ // 현재 노드와 인접 노드들 모두 확인
            int cost_there = graph[here][i].second;
            int there = graph[here][i].first;

            /* 최단거리 체크 후 갱신 & 다음 정점 우선순위 큐에 넣기*/
            if (dist[there] > cost_here + cost_there){
                dist[there] = cost_here + cost_there;
                pq.push(make_pair(dist[there], there));
            }
        }
    }
}

int main (){
    scanf("%d %d", &v, &e);

    int start;
    scanf("%d", &start);

    /* 그래프 만들기 graph[출발점][<도착점, 거리>] */
    for (int i = 0 ; i < e ; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
    }

    initSP(); // INF로 초기화
    setStart(start); // 시작점 설정
    daijkstra(); // 최단경로 계산
    
    for (int i = 1 ; i <= v ; i++){
        dist[i] == INF ? printf("INF\n") : printf("%d\n", dist[i]);
    }
}
