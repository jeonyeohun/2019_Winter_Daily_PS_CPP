#include <iostream>
#include <algorithm>

using namespace std;

int board[500][500];
int block[19][3][2] = {

    /* Pattern 1
     * 1 1 1 1
     */
    {{0, 1}, {0, 2}, {0, 3}},

    /* Pattern 2
     * 1
     * 1
     * 1
     * 1
     */

    {{1, 0}, {2, 0}, {3, 0}},

    /* Pattern 3
     * 1
     * 1
     * 1 1
     */
    {{1, 0}, {2, 0}, {2, 1}},

    /* Pattern 4
     *   1
     *   1
     * 1 1
     */
    {{1, 0}, {2, 0}, {2, -1}},

    /* Pattern 5
     * 1
     * 1 1 1
     */
    {{1, 0}, {1, 1}, {1, 2}},

    /* Pattern 6
     *     1
     * 1 1 1
     */
    {{1, 0}, {1, -1}, {1, -2}},

    /* Pattern 7
     * 1 1
     * 1
     * 1
     */
    {{0, 1}, {1, 0}, {2, 0}},

    /* Pattern 8
     * 1 1 1
     *     1
     */
    {{0, 1}, {0, 2}, {1, 2}},

    /* Pattern 9
     * 1 1 1
     * 1
     */
    {{1, 0}, {0, 1}, {0, 2}},

    /* Pattern 10
     * 1 1
     *   1
     *   1
     */
    {{0, 1}, {1, 1}, {2, 1}},

    /* Pattern 11
     * 1 1
     * 1 1
     */
    {{0, 1}, {1, 0}, {1, 1}},

    /* Pattern 12
     * 1
     * 1 1
     *   1
     */
    {{1, 0}, {1, 1}, {2, 1}},

    /* Pattern 13
     *   1
     * 1 1
     * 1
     */
    {{1, 0}, {1, -1}, {2, -1}},

    /* Pattern 14
     * 1 1
     *   1 1
     */
    {{0, 1}, {1, 1}, {1, 2}},

    /* Pattern 15
     *   1 1
     * 1 1
     */
    {{0, 1}, {1, 0}, {1, -1}},

    /* Pattern 16
     * 1
     * 1 1
     * 1
     */
    {{1, 0}, {2, 0}, {1, 1}},

    /* Pattern 17
     *   1
     * 1 1
     *   1
     */
    {{1, 0}, {1, -1}, {2, 0}},

    /* Pattern 18
     *   1
     * 1 1 1
     */
    {{1, -1}, {1, 0}, {1, 1}},

    /* Pattern 19
     * 1 1 1
     *   1
     */
    {{0, 1}, {0, 2}, {1, 1}},
};

int main()
{
    int N, M;
    int answer = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // try all 19 block patterns for board[i][j]
            for (int k = 0; k < 19; k++)
            {
                // set initial value with the starting point of the pattern
                int sum = board[i][j];
                for (int l = 0; l < 3; l++)
                {
                    // take x, y coordinate from blocks
                    int x = i + block[k][l][0];
                    int y = j + block[k][l][1];

                    // Check if the coordinate is over board
                    if (0 <= x && x < N && 0 <= y && y < M)
                    {
                        sum += board[x][y];
                    }
                    else
                    {
                        sum = 0;
                        break;
                    }
                }
                answer = max(answer, sum);
            }
        }
    }

    printf("%d", answer);
}
