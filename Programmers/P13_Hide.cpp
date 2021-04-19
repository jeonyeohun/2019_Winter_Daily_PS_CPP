#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> types;
    for (int i = 0; i < clothes.size(); i++) {
        if (types.find(clothes[i][1]) != types.end()) {
            types[clothes[i][1]]++;
        }
        else {
            types.insert({ clothes[i][1], 1 });
        }
    }

    if (types.size() == 1) return clothes.size();

    int sum = 1;
    for (auto iter = types.begin(); iter != types.end(); iter++) {
        sum *= iter->second + 1;
    }

    return sum - 1;
}
