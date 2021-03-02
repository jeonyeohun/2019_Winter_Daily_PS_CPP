#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int M, N, x, y;
        scanf("%d %d %d %d", &M, &N, &x, &y);

        // 나머지를 맞추기 위해 1씩 빼준다.
        x -= 1;
        y -= 1;

        // i 는 M으로 나눈 나머지가 x가 되는 수 -> x를 M으로 가지는 해
        int i;
        for (i = x; i < (M * N); i += M)
        {
            // M 과 N 이 모두 일치해야 하기 때문에 i를 N으로 나눴을 때 나머지가 y가 되는 해을 찾는다. -> y를 N으로 가지는 해
            if (i % N == y)
            {
                printf("%d\n", i + 1); // 다시 1을 더해주어야 실제 값이 나온다.
                break;
            }
        }

        // 정답을 찾지 못한 경우
        if (i >= (M * N))
        {
            printf("-1\n");
        }
    }
}
