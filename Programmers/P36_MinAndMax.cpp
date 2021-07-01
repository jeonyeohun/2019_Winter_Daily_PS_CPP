
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    istringstream ss(s);
    string stringBuffer;

    int minNum = INT_MAX;
    int maxNum = INT_MIN;
    while (getline(ss, stringBuffer, ' ')) {
        int num;
        istringstream toInt(stringBuffer);
        toInt >> num;

        minNum = min(minNum, num);
        maxNum = max(maxNum, num);
    }

    answer = to_string(minNum) + " " + to_string(maxNum);
    return answer;
}
