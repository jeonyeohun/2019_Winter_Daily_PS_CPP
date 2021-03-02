#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int numbers[14];
vector<int> comb;
bool visited[14];
set<vector<int>> answer;

void dfs(int cnt, int max)
{
    if (cnt == 6)
    {
        vector<int> temp;
        temp.assign(comb.begin(), comb.end());
        sort(temp.begin(), temp.end());
        answer.insert(temp);
        return;
    }

    for (int i = 0; i < max; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            comb.push_back(numbers[i]);
            dfs(cnt + 1, max);
            visited[i] = false;
            comb.pop_back();
        }
    }
}

int main()
{
    int k;
    while (true)
    {
        scanf("%d", &k);
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &numbers[i]);
        }

        dfs(0, k);

        for (auto s : answer)
        {
            for (auto i : s)
            {
                printf("%d ", i);
            }
            printf("\n");
        }
        printf("\n");

        comb.clear();
        answer.clear();
    }
}
