#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmpMap(const pair<string, vector<pair<int, int>>>& a, const pair<string, vector<pair<int, int>>>& b) {
    int sumA = 0;
    for (auto aPlays : a.second) {
        sumA += aPlays.first;
    }

    int sumB = 0;
    for (auto bPlays : b.second) {
        sumB += bPlays.first;
    }

    return sumB < sumA;
}


bool cmpVec(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> musics;

    for (int i = 0; i < genres.size(); i++) {
        if (musics.find(genres[i]) != musics.end()) {
            musics[genres[i]].push_back({ plays[i], i });
            sort(musics[genres[i]].begin(), musics[genres[i]].end(), cmpVec);
        }
        else {
            vector<pair<int, int>> temp;
            temp.push_back({ plays[i], i });
            musics.insert({ genres[i], temp });
        }
    }

    vector<pair<string, vector<pair<int, int>>>> clonedMusics;

    clonedMusics.assign(musics.begin(), musics.end());
    sort(clonedMusics.begin(), clonedMusics.end(), cmpMap);

    for (auto type : clonedMusics) {
        int pushCount = 0;
        for (auto music : type.second) {
            answer.push_back(music.second);
            pushCount++;
            if (pushCount % 2 == 0) break;
        }
    }

    return answer;
}