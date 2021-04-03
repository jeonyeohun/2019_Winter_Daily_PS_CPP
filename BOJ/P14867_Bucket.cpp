#include <iostream>
#include <queue>
#include <set>

using namespace std;

pair<int, int> fillBucket(pair<int, int> x) {
    x.first = x.second;
    return x;
}

pair<int, int> emptyBucket(pair<int, int> x) {
    x.first = 0;
    return x;
}

pair<pair<int, int>, pair<int, int>> moveXtoY(pair<int, int> x, pair<int, int> y) {
    if (x.first <= y.second - y.first) {
        y.first += x.first;
        x.first = 0;
    }
    else {
        x.first = x.first - (y.second - y.first);
        y.first = y.second;
    }
    return { x, y };
}


int bfs(pair<int, int> A, pair<int, int> B, int targetA, int targetB) {
    queue<pair<pair<int, int>, pair<int, int>>> bucketStatus;
    set<int> visited[100001];
    bucketStatus.push({ A, B });
    int depth = 0;

    while (!bucketStatus.empty()) {
        size_t size = bucketStatus.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> currA = bucketStatus.front().first;
            pair<int, int> currB = bucketStatus.front().second;
            bucketStatus.pop();

            if (currA.first == targetA && currB.first == targetB) {
                return depth;
            }

            auto fillA = fillBucket(currA);
            auto fillB = fillBucket(currB);
            auto emptyA = emptyBucket(currA);
            auto emptyB = emptyBucket(currB);
            auto moveX = moveXtoY(currA, currB);
            auto moveY = moveXtoY(currB, currA);

            if (visited[fillA.first].find(currB.first) == visited[fillA.first].end()) {
                visited[fillA.first].insert(currB.first);
                bucketStatus.push({ fillA, currB });
            }
            if (visited[currA.first].find(fillB.first) == visited[currA.first].end()) {
                visited[currA.first].insert(fillB.first);
                bucketStatus.push({ currA, fillB });
            }
            if (visited[emptyA.first].find(currB.first) == visited[emptyA.first].end()) {
                visited[emptyA.first].insert(currB.first);
                bucketStatus.push({ emptyA, currB });
            }
            if (visited[currA.first].find(emptyB.first) == visited[currA.first].end()) {
                visited[currA.first].insert(emptyB.first);
                bucketStatus.push({ currA, emptyB });
            }
            if (visited[moveX.first.first].find(moveX.second.first) == visited[moveX.first.first].end()) {
                visited[moveX.first.first].insert(moveX.second.first);
                bucketStatus.push(moveX);
            }
            if (visited[moveY.second.first].find(moveY.first.first) == visited[moveY.second.first].end()) {
                visited[moveY.second.first].insert(moveY.first.first);
                bucketStatus.push({ moveY.second, moveY.first });
            }
        }
        depth++;
    }
    return -1;
}

int main() {
    int a, b, targetA, targetB;
    cin >> a >> b >> targetA >> targetB;

    pair<int, int> A = { 0, a };
    pair<int, int> B = { 0, b };

    cout << bfs(A, B, targetA, targetB);
}
