#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indegree[32001] = { 0, };


void topologicalSort(int size, queue<int>& problemOrder, vector<vector<int>>& problems) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= size; i++) {
        if (indegree[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        int vertex = pq.top();
        pq.pop();
        problemOrder.push(vertex);

        for (auto next : problems[vertex]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                pq.push(next);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> problems(N + 1);
    queue<int> problemOrder;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        problems[a].push_back(b);
        indegree[b]++;
    }

    topologicalSort(N, problemOrder, problems);

    while (!problemOrder.empty()) {
        cout << problemOrder.front() << " ";
        problemOrder.pop();
    }
}
