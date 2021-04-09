#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int A[N];
    int B[M];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    int startA, endA, startB, endB;
    startA = endA = startB = endB = 0;

    int sum[N + M];
    int sumIdx = 0;


    while (startA != N || startB != M) {
        if (A[startA] < B[startB]) {
            sum[sumIdx++] = A[startA++];
        }
        else {
            sum[sumIdx++] = B[startB++];
        }
    }

    while (startA != N) {
        sum[sumIdx++] = A[startA++];
    }

    while (startB != M) {
        sum[sumIdx++] = B[startB++];
    }

    for (int i = 0; i < N + M; i++) {
        cout << sum[i] << " ";
    }
}