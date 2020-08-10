#include <cstdio>
#include <vector>

using namespace std;

int main (){
    int N;
    vector <pair<int, int>> schedule;
    scanf("%d", &N);

    for (int i = 0 ; i < N ; i++){
        int T, P;
        scanf("%d %d", &T, &P);

        schedule.push_back({T, P});

    }
}