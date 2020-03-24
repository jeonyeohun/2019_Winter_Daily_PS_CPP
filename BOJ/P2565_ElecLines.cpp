#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // max 함수를 쓰기 위해

using namespace std;

int dp[101] = {0}; // dp를 위한 배열. 전깃줄의 최대 갯수는 100개이다.

int main()
{
    int T;
    cin >> T;
    set<pair<int, int>> bot; // pair로 받는다. set 자료구조에 넣기 때문에 first를 기준으로 정렬된다.
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        bot.insert(make_pair(a, b)); // set에 insert하기
    }

    vector<int> b;
    for (auto it = bot.begin(); it != bot.end(); it++)
    {
        b.push_back(it->second); // 이 작업은 사실 안해도 되긴 하는데, lis계산을 편하게 하기 위해서 만들었다. second만 모아서 새 벡터에 저장.
    }

    // LIS를 구하는 식. O(n^2)이다.
    for (int i = 0; i < b.size(); i++)
    {
        if (dp[i] == 0)
            dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (b[i] > b[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // 부분 수열 중 가장 길이가 긴 녀석을 찾자.
    int lis = 0;
    for (int i = 0; i < b.size(); i++)
    {
        lis = max(lis, dp[i]);
    }

    // 전체 크기에서 빼주면 없애야할 전깃줄의 갯수가 나온다.
    cout << b.size() - lis;
    return 0;
}
