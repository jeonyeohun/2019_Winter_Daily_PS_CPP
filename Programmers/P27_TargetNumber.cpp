#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int target, int sum, int idx) {
    if (idx == numbers.size()) {
        return sum == target ? 1 : 0;
    }

    return dfs(numbers, target, sum + numbers[idx], idx + 1)
        + dfs(numbers, target, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}