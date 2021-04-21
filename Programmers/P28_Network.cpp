#include <string>
#include <vector>

using namespace std;

void dfs(int start, vector<bool>& visited, vector<vector<int>> computers) {
    visited[start] = true;

    for (int i = 0; i < computers[start].size(); i++) {
        if (computers[start][i] && !visited[i]) {
            dfs(i, visited, computers);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<bool> visited(computers.size() + 1, false);
    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            dfs(i, visited, computers);
            answer++;
        }
    }
    return answer;
}