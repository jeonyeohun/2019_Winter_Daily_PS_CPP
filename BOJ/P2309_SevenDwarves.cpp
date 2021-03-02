
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10;

vector<int> dwarves(10);

void printSolution(int i, int j)
{
    for (int d = 1; d < MAX; d++)
    {
        if (d != i && d != j)
        {
            printf("%d\n", dwarves[d]);
        }
    }
}

int main()
{
    int sum = 0;
    for (int i = 1; i <= 9; i++)
    {
        scanf("%d", &dwarves[i]);
        sum += dwarves[i];
    }

    sort(dwarves.begin(), dwarves.end());

    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; j < MAX; j++)
        {
            if (j == i)
                continue;
            if (sum - dwarves[i] - dwarves[j] == 100)
            {
                printSolution(i, j);
                return 0;
            }
        }
    }
}
