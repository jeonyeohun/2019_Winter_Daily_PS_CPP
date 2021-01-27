#include <list>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

list<char> editor;

int main()
{
    int M;
    string str;
    cin >> str;
    editor.assign(str.begin(), str.end());
    list<char>::iterator iter = editor.end();

    cin >> M;

    while (M--)
    {
        char op;
        char c;
        cin >> op;
        switch (op)
        {
        case 'L':
            if (iter != editor.begin())
                iter--;
            break;
        case 'D':
            if (iter != editor.end())
                iter++;
            break;
        case 'B':
            if (iter != editor.begin())
                iter = editor.erase(--iter);
            break;
        case 'P':
            cin >> c;
            editor.insert(iter, c);
        }
    }

    for (char e : editor)
    {
        printf("%c", e);
    }
}