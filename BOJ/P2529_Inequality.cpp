#include <iostream>
#include <vector>

using namespace std;

vector<char> ops;
vector<int> comb;
vector<int> MIN;
vector<int> MAX;
bool visited[10];

void backTracking(int cnt, int k)
{
    if (cnt == k + 1)
    {
        bool findResult = true;
        for (int i = 0; i < ops.size(); i++)
        {
            int left = comb[i];
            int right = comb[i + 1];
            if ((ops[i] == '<' && left > right) || (ops[i] == '>' && left < right))
            {
                findResult = false;
            }
        }

        if (!findResult)
            return;

        if (MIN.empty())
            MIN.assign(comb.begin(), comb.end());
        else
            MAX.assign(comb.begin(), comb.end());

        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            comb.push_back(i);
            backTracking(cnt + 1, k);
            comb.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        char op;
        cin >> op;

        ops.push_back(op);
    }

    backTracking(0, k);

    for (auto m : MAX)
    {
        cout << m;
    }
    cout << "\n";
    for (auto m : MIN)
    {
        cout << m;
    }
}
