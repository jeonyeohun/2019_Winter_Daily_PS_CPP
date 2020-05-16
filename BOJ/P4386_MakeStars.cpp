
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int parent[101];
int level[101];

vector<pair<double, double>> stars;
vector<pair<double, pair<int, int>>> edges ; // <간선길이, <출발점, 도착점>>

double calcDist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int find (int a){
    if (a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

bool merge (int a, int b){
    a = find(a);
    b = find(b);

    if (a == b) return false;

    if(level[a] > level[b]) parent[a] = b;
    else parent[b] = a;

    if (level[a] == level[b]) level[a]++;
    return true;
}

int main (){
    int n;
    scanf("%d", &n);
    int v = n;

    /* get position of stars */
    while(n--){
        double x, y;
        scanf("%lf %lf", &x, &y);
        stars.push_back({x, y});
    }

    /* build graph by getting edges for all stars */
    for (int i = 0 ; i < stars.size() ;i++){
        for (int j = i+1 ; j < stars.size() ; j++){
            edges.push_back({calcDist(stars[i].first, stars[i].second, stars[j].first, stars[j].second), {i, j}});
        }
    }

    /* intialize parent array for union-find */
    for (int i = 0 ; i < v ; i++){
        parent[i] = i;
    }

    /* sort edges by their weights for greedy approach */
    sort(edges.begin(), edges.end());

    double ret = 0;
    for (int i = 0 ; i < edges.size() ; i++){
        /* add all min-weight edges that does not make cycle */
        if(merge(edges[i].second.first, edges[i].second.second)){
            ret += edges[i].first;
        }
    }

    printf("%0.2f", ret);

}