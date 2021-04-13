#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int cnt = 0;
    for (int h = 0; h <= N; h++) {
        for (int m = 0; m < 60; m++) {
            for (int s = 0; s < 60; s++) {
                string hour, minute, second;
                if (h < 10) hour = '0';
                if (m < 10) minute = '0';
                if (s < 10) second = '0';

                hour += to_string(h);
                minute += to_string(m);
                second += to_string(s);
                string time = hour + minute + second;
                string kStr = to_string(K);

                if (time.find(kStr) != string::npos) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
}
