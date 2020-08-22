#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++) {
        string c = completion[i];
        string p = participant[i];

        if (c.compare(p)) return p;
    }

    return participant.back();
}