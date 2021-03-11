#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int N;
    priority_queue<int, vector<int>, greater<int> > pq;
    scanf("%d", &N);

    vector<int> cards;
    while (N--)
    {
        int card;
        scanf("%d", &card);
        pq.push(card);
    }

    int sum = 0;

    while (pq.size() != 1)
    {
        int cardFirst = pq.top();
        pq.pop();
        int cardSecond = pq.top();
        pq.pop();

        pq.push(cardFirst + cardSecond);
        sum += cardFirst + cardSecond;
    }

    printf("%d", sum);
}
