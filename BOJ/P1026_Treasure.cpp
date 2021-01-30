#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int A[51];
    int B[51];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &B[i]);
    }

    sort(A, A + N, greater<int>());
    sort(B, B + N);

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i] * B[i];
    }

    printf("%d", sum);
}