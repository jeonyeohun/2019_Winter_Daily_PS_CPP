#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> numbers;
    vector<int> freq(8001, 0);

    for (int i = 0; i < N; i++)
    {
        int in;
        cin >> in;
        numbers.push_back(in);

        if (in < 0)
            freq[4001 + in * -1]++; // 출현 횟수 기억하기. 0은 0번째, 1~4000은 1~4001번째, -1~-4000은 4002~8001번째에 저장
        else
            freq[in]++;
    }

    sort(numbers.begin(), numbers.end());

    cout << round((double)accumulate(numbers.begin(), numbers.end(), 0) / (double)N) << "\n"; // 산술평균 계산

    cout << numbers[numbers.size() / 2] << "\n"; // 중앙값 계산

    vector<int> v;
    int max = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] > max)
            max = freq[i]; // 최다 빈도 수 찾기
    }

    // 가장 많이 나온 수들을 모두 찾는다
    for (int i = 0; i < freq.size(); i++)
    {
        int num;
        if (freq[i] == max)
        {
            if (i > 4001)
                v.push_back(i * -1 + 4001);
            else
                v.push_back(i);
        }
    }
    // 여러개의 최빈 값 정렬하기
    sort(v.begin(), v.end());
    if (v.size() > 1)
        cout << v[1] << "\n"; // 최빈값이 여러개면 1번째 인덱스에 있는 값(2번째로 작은 값) 출력
    else
        cout << v[0] << "\n"; // 최빈값이 하나면 그대로 출력

    cout << numbers[numbers.size() - 1] - numbers[0] << "\n"; // 수의 범위 출력

    return 0;
}