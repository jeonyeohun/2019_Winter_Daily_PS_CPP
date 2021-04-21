#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> aggTriangle(triangle.begin(), triangle.end());


    for (int i = 0; i < aggTriangle.size() - 1; i++) {
        for (int j = 0; j < aggTriangle[i].size(); j++) {
            aggTriangle[i + 1][j] = max(aggTriangle[i + 1][j], aggTriangle[i][j] + triangle[i + 1][j]);
            aggTriangle[i + 1][j + 1] = max(aggTriangle[i + 1][j + 1], aggTriangle[i][j] + triangle[i + 1][j + 1]);

            answer = max(answer, max(aggTriangle[i + 1][j], aggTriangle[i + 1][j + 1]));
        }
    }

    return answer;
}