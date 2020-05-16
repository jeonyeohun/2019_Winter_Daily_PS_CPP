#include <cstdio>
#include <vector>
#include <climits>

#define INF 7000000
using namespace std;

typedef struct{
    int here;
    int there;
    int cost;
}edge;

long long d [501] = {0,};
vector<edge> edges;

int main (){
    int v, e;
    scanf("%d %d", &v, &e);
    for (int i = 2 ; i <= v ; i++) d[i] = INF;
    for (int i = 0 ; i < e ; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back({a, b, c});
    }

     for (int i = 1 ; i <= v-1 ; i++){
        for (int j = 0 ; j < e ; j++){
            int from = edges[j].here;
            int to = edges[j].there;
            int w = edges[j].cost;

            if (d[from] == INF) continue;
            if (d[to] > d[from] + w) d[to] = d[from] + w;
        }
    }

    for (int i = 1 ; i <= v-1 ; i++){
        for (int j = 0 ; j < e ; j++){
            int from = edges[j].here;
            int to = edges[j].there;
            int w = edges[j].cost;

            if (d[from] == INF) continue;

            if (d[to] > d[from] + w) {
                printf("-1\n");
                return 0;
            }
        }
    }

    for (int i = 2 ; i <= v ; i++){
        d[i]==INF ? printf("-1\n") : printf("%lld\n", d[i]);
    }

}