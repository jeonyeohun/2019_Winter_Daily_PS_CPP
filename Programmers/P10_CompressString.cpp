#include <string>
#include <vector>

using namespace std;

int compress(string str, int group) {
    int basis = 0;
    string newString = "";
    if (str.size() / 2 < group) return str.size();

    int count = 0;
    while (basis != str.size()) {
        int nextPos = basis + group * (count + 1);
        if (nextPos > str.size()) {
            string last = str.substr(basis, str.size() - basis);
            newString += last;
            break;
        }
        string basisSubStr = str.substr(basis, group);
        string nextSubStr = str.substr(nextPos, group);

        if (basisSubStr.compare(nextSubStr) == 0) {
            count++;
        }
        else {
            basis = nextPos;
            if (count != 0)newString += to_string(count + 1) + basisSubStr;
            else newString += basisSubStr;

            count = 0;
        }
    }
    return newString.size();
}

int solution(string s) {
    int minLen = s.size();

    for (int i = 1; i < s.size(); i++) {
        minLen = min(minLen, compress(s, i));
    }
    return minLen;
}