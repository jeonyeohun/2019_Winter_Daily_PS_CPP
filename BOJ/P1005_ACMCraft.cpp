#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(queue<int>& buildOrder, int N, vector<int>& inDegree, vector<vector<int>>& adj) {
    while (buildOrder.size() != N) {
        for (int i = 1; i < adj.size(); i++) {
            if (inDegree[i] == 0) {
                inDegree[i] = -1;
                buildOrder.push(i);
                for (auto next : adj[i]) {
                    inDegree[next]--;
                }
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<vector<int>> adj(N + 1);
        vector<vector<int>> reverseAdj(N + 1);
        vector<int> inDegree(N + 1);
        vector<int> cost(N + 1);
        vector<int> dp(N + 1, 0);
        queue<int> buildOrder;

        for (int i = 1; i <= N; i++) {
            cin >> cost[i];
            dp[i] = cost[i];
        }

        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            reverseAdj[b].push_back(a);
            inDegree[b]++;
        }

        topologicalSort(buildOrder, N, inDegree, adj);

        while (!buildOrder.empty()) {
            int curr = buildOrder.front();
            for (auto prev : reverseAdj[curr]) {
                dp[curr] = max(dp[curr], dp[prev] + cost[curr]);
            }
            buildOrder.pop();
        }

        int W;
        cin >> W;
        cout << dp[W] << "\n";
    }
}