#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int N, M, target;
    map<int, int> cards;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int card;
        scanf("%d", &card);
        cards[card]++;
    }

    scanf("%d", &M);
    while (M--)
    {
        scanf("%d", &target);
        auto iter = cards.find(target);
        if (iter == cards.end())
            printf("0 ");
        else
            (printf("%d ", (*iter).second));
    }
}