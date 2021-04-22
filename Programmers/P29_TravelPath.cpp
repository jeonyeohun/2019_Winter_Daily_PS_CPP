#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int N;
set<vector<string>> paths;

void dfs(map<string, vector<string>> routes,
    map<pair<string, string>, int>& visited,
    string now,
    vector<string>& answer) {

    if (answer.size() == N + 1) {
        paths.insert(answer);
    }

    for (auto next : routes[now]) {
        if (visited[{now, next}] != 0) {
            visited[{now, next}]--;
            answer.push_back(next);
            dfs(routes, visited, next, answer);
            answer.pop_back();
            visited[{now, next}]++;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, vector<string>> routes;
    map<pair<string, string>, int> visited;
    N = tickets.size();

    for (auto ticket : tickets) {
        if (routes.find(ticket[0]) == routes.end()) {
            routes.insert({ ticket[0], {ticket[1]} });
            visited.insert({ {ticket[0], ticket[1]}, 1 });
        }
        else {
            routes[ticket[0]].push_back({ ticket[1] });
            visited[{ticket[0], ticket[1]}]++;
            sort(routes[ticket[0]].begin(), routes[ticket[0]].end());
        }
    }

    answer.push_back("ICN");
    dfs(routes, visited, "ICN", answer);
    return *(paths.begin());
}