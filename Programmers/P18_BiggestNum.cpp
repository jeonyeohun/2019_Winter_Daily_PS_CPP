#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& a, string& b) {
    string ab = a + b;
    string ba = b + a;
    return ba < ab;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNums;

    for (auto num : numbers) {
        strNums.push_back(to_string(num));
    }

    sort(strNums.begin(), strNums.end(), cmp);

    for (auto num : strNums) {
        if (answer.empty() && num == "0") continue;
        answer += num;
    }

    if (answer.empty()) answer.push_back('0');
    return answer;
}