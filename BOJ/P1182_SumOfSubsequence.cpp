#include <cstdio>

using namespace std;

int N, S;
int numbers[21];
int answer = 0;

void search(int idx, int sum)
{
    sum += numbers[idx];
    if (idx >= N)
        return;
    if (sum == S)
        answer++;

    search(idx + 1, sum - numbers[idx]); // 다음 숫자를 더하지 않는 경우
    search(idx + 1, sum);                // 다음 숫자를 더하는 경우
}

int main()
{
    scanf("%d %d", &N, &S);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numbers[i]);
    }
    search(0, 0);

    printf("%d", answer);
}
