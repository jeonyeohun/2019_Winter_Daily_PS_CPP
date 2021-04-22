#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(string begin, string target, vector<string> words) {
    queue<string> q;
    vector<bool> visited(words.size());
    q.push(begin);
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            string now = q.front();
            q.pop();

            if (now == target) return steps;

            for (int j = 0; j < words.size(); j++) {
                int cnt = 0;
                for (int k = 0; k < words[j].size(); k++) {
                    if (words[j][k] != now[k]) cnt++;
                }
                if (cnt == 1) {
                    q.push(words[j]);
                }
            }
        }
        steps++;
    }
    return steps;
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) return 0;
    return bfs(begin, target, words);
}