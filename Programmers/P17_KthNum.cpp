#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto command : commands) {
        int start = command[0] - 1;
        int end = command[1];
        int target = command[2];

        vector<int> subArray(array.begin() + start, array.begin() + end);


        sort(subArray.begin(), subArray.end());
        answer.push_back(subArray[target - 1]);
    }
    return answer;
}