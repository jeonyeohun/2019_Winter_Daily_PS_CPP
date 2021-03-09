#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> trees;

long long calcTree(long long height)
{
    long long sum = 0;
    for (auto tree : trees)
    {
        long long leftOver = tree - height;
        if (leftOver > 0)
            sum += leftOver;
    }

    return sum;
}

long long binarySearch(long long target)
{
    long long begin = 0;
    long long end = trees.back();
    long long closest = 0;

    while (begin <= end)
    {
        long long mid = (begin + end) / 2;
        long long calcResult = calcTree(mid);

        if (calcResult == target)
            return mid;
        else if (calcResult < target)
        {
            end = mid - 1;
        }
        else if (calcResult > target)
        {
            closest = mid;
            begin = mid + 1;
        }
    }

    return closest;
}

int main()
{
    long long N, M;
    scanf("%lld %lld", &N, &M);

    for (int i = 0; i < N; i++)
    {
        int tree;
        scanf("%d", &tree);
        trees.push_back(tree);
    }

    sort(trees.begin(), trees.end());

    printf("%lld", binarySearch(M));
}
