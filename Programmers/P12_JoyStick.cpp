#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
    string initialName;
    for (int i = 0; i < name.size(); i++) {
        initialName.push_back('A');
    }

    int cursor = 0;
    int count = 0;
    while (true) {
        count += min((name[cursor] - 'A'), ('Z' - name[cursor] + 1));
        initialName[cursor] = name[cursor];

        if (initialName.compare(name) == 0) break;


        int nextLeftIdx = cursor;
        int nextLeftCount = 0;
        while (initialName[nextLeftIdx] == name[nextLeftIdx]) {
            nextLeftIdx--;
            nextLeftCount++;

            if (nextLeftIdx < 0) nextLeftIdx = name.size() - 1;
        }

        int nextRightIdx = cursor;
        int nextRightCount = 0;

        while (initialName[nextRightIdx] == name[nextRightIdx]) {
            nextRightIdx++;
            nextRightCount++;

            if (nextRightIdx == name.size()) nextRightIdx = 0;
        }


        count += nextRightCount <= nextLeftCount ? nextRightCount : nextLeftCount;
        cursor = nextRightCount <= nextLeftCount ? nextRightIdx : nextLeftIdx;
    }
    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        cout << solution(s) << "\n";
    }
}