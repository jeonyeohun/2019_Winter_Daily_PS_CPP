#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;

    vector<vector<int>> adj(a.size());
    vector<int> inDegree(300001, 0);

    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
    }
    if (sum != 0) return -1;

    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        inDegree[edge[1]]++;
        inDegree[edge[0]]++;
    }

    int nodeLeft = a.size();
    int size = a.size();
    int i = 0;
    vector<long long> accumulatedSum;
    accumulatedSum.assign(a.begin(), a.end());
    while (nodeLeft > 1) {
        for (int i = 0; i < a.size(); i++) {
            if (inDegree[i] == 1) {
                inDegree[i] = -1;
                for (auto next : adj[i]) {
                    if (inDegree[next] != -1) {
                        accumulatedSum[next] += accumulatedSum[i];
                        answer += abs(accumulatedSum[i]);
                        accumulatedSum[i] = 0;
                        inDegree[next]--;
                    }
                }
                nodeLeft--;
            }
        }
    }
    return answer;
}