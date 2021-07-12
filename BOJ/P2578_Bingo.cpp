#include <iostream>
#include <vector>

using namespace std;

bool isLeftDigUsed = false;
bool isRightDigUsed = false;

int isDiagonalClear(vector<vector<int>>& map) {
    int countLeft = 0;
    int countRight = 0;
    int bingoCount = 0;
    for (int i = 0; i < 5; i++) {
        if (map[i][i] == -1) countLeft++;
        if (map[i][4 - i] == -1) countRight++;
    }

    if (countLeft == 5 && !isLeftDigUsed) {
        isLeftDigUsed = true;
        bingoCount++;
    }
    if (countRight == 5 && !isRightDigUsed) {
        isRightDigUsed = true;
        bingoCount++;
    }

    return bingoCount;
}

bool isRowClear(vector<vector<int>>& map, int row) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (map[row][i] == -1) count++;
    }

    return count == 5;
}

bool isColClear(vector<vector<int>>& map, int col) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (map[i][col] == -1) count++;
    }

    return count == 5;
}

pair<int, int> getIndex(vector<vector<int>>& map, int target) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (map[i][j] == target) return { i, j };
        }
    }

    return { -1, -1 };
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    vector<vector<int>> map(5, vector<int>(5, 0));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> map[i][j];
        }
    }

    int count;
    int bingoCount = 0;
    for (count = 1; count <= 25; count++) {
        int num; cin >> num;

        pair<int, int> index = getIndex(map, num);
        map[index.first][index.second] = -1;


        bingoCount += isDiagonalClear(map)
            + isColClear(map, index.second)
            + isRowClear(map, index.first);
        if (bingoCount >= 3) break;
    }

    cout << count;
}
