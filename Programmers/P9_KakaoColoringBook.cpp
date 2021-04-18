#include <vector>

using namespace std;

int rowMax = 0;
int colMax = 0;

bool isInBound(int row, int col) {
    return row <= rowMax && col <= colMax && row >= 0 && col >= 0;
}

int dfs(int row, int col, vector<vector<int>>& picture, vector<vector<bool>>& visited, int count) {
    int rowDir[] = { 0, 0, 1, -1 };
    int colDir[] = { 1, -1, 0, 0 };
    visited[row][col] = true;

    for (int i = 0; i < 4; i++) {
        int rowNext = row + rowDir[i];
        int colNext = col + colDir[i];

        if (isInBound(rowNext, colNext)
            && !visited[rowNext][colNext]
            && picture[row][col] == picture[rowNext][colNext]) {
            count = dfs(rowNext, colNext, picture, visited, count + 1);
        }
    }
    return count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    rowMax = m - 1;
    colMax = n - 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && picture[i][j] != 0) {
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, dfs(i, j, picture, visited, 1));
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}