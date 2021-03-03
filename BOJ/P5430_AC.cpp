#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void R(bool &isReverse)
{
    isReverse = !isReverse;
}

bool D(deque<int> &dq, bool &isReverse)
{
    if (dq.size() == 0)
        return false;
    else if (isReverse)
        dq.pop_back();
    else if (!isReverse)
        dq.pop_front();

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;

    while (T--)
    {
        deque<int> dq;
        string ops;
        string arr;
        bool isReverse = false;
        int n;

        cin >> ops;
        cin >> n;
        cin >> arr;
        arr.erase(0, 1);
        arr.pop_back();

        string stringBuffer;
        istringstream ss(arr);
        while (getline(ss, stringBuffer, ','))
        {
            int num = stoi(stringBuffer);
            dq.push_back(num);
        }

        bool isNotError = true;
        for (int i = 0; i < ops.size(); i++)
        {
            if (ops[i] == 'R')
            {
                R(isReverse);
            }
            if (ops[i] == 'D')
            {
                isNotError = D(dq, isReverse);
            }
        }

        if (!isNotError)
        {
            cout << "error"
                 << "\n";
        }
        else if (dq.size() == 0)
            cout << "[]"
                 << "\n";
        else if (!isReverse)
        {
            cout << "[";
            for (auto iter = dq.begin(); iter != dq.end(); iter++)
            {
                if (iter == dq.end() - 1)
                    cout << *iter;
                else
                    cout << *iter << ",";
            }
            cout << "]\n";
        }
        else
        {
            cout << "[";
            for (auto iter = dq.end() - 1; iter != dq.begin() - 1; iter--)
            {
                if (iter == dq.begin())
                    cout << *iter;
                else
                    cout << *iter << ",";
            }
            cout << "]\n";
        }
    }
}
