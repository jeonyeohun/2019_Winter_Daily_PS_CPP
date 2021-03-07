#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100001;
bool visited[MAX];
bool searchDone[MAX];
int stepCount[MAX];
int cnt = 0;

void dfs(int now, int origin, int adj[MAX][1])
{
    visited[now] = true;
    int next = adj[now][0];

    if (!visited[next])
    {
        stepCount[next] = stepCount[now] + 1;
        dfs(next, origin, adj);
    }
    else if (!searchDone[next])
    {
        cnt += (stepCount[now] - stepCount[next] + 1);
    }

    searchDone[now] = true;
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int students;
        scanf("%d", &students);

        int selections[MAX][1];

        for (int i = 0; i <= students; i++)
        {
            visited[i] = false;
            searchDone[i] = false;
            stepCount[i] = 0;
        }

        for (int i = 1; i <= students; i++)
        {
            scanf("%d", &selections[i][0]);
        }

        for (int i = 1; i <= students; i++)
        {
            if (!visited[i])
            {
                dfs(i, i, selections);
            }
        }

        printf("%d\n", students - cnt);
        cnt = 0;
    }
}
