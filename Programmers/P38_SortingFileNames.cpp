#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findNumberIndex(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) return i;
    }
    return s.size();
}

string toLowerString(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

string parseHead(string s) {
    return toLowerString(s.substr(0, findNumberIndex(s)));
}

int findLastNumberIndex(int start, string s) {
    for (int i = start; i < s.size(); i++) {
        if (!isdigit(s[i])) return i;
    }
    return s.size();
}

int parseNumber(string s) {
    int start = findNumberIndex(s);
    int end = findLastNumberIndex(start, s);
    string number = s.substr(start, end);
    return stoi(number);
}

bool compareNumber(string a, string b) {
    return parseNumber(a) < parseNumber(b);
}

bool compareHead(string a, string b) {
    return parseHead(a) < parseHead(b);
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compareNumber);
    stable_sort(files.begin(), files.end(), compareHead);
    return files;
}