#include <vector>
#include <string>
#include <iostream>

using namespace std;

int N;
string sequence = "";

bool isDup(string s)
{
    int len = s.length();
    int start = len - 1;

    for (int i = 1; i <= len / 2; i++)
    {                                          // 반복되는 부분수열이 될 수 있는 최대 길이
        string first = s.substr(start - i, i); // 기준 부분수열을 하나씩 줄이면서
        string second = s.substr(start, i);    // 반복되는 부분수열이 있는지 검사한다.
        if (first.compare(second) == 0)
            return true;
        --start;
    }
    return false;
}

void search(int cnt)
{
    if (cnt == N)
    {
        cout << sequence;
        exit(0);
    }

    for (int i = 1; i <= 3; i++)
    {
        sequence.push_back('0' + i);
        if (!isDup(sequence))
        { // 나쁜 수열이 없을 때만 새로운 숫자를 추가한다.
            search(cnt + 1);
        }
        sequence.pop_back();
    }
}

int main()
{
    cin >> N;
    search(0);
}
