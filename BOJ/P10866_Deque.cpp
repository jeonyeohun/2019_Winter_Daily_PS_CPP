#include <iostream>
#include <string>

using namespace std;

#define MAX 10001

int deque [2 * MAX + 1];
int head = MAX;
int tail = MAX;
int len = 0;

int empty(){
    return head == tail;
}

void push_front(int x){
    deque[--head] = x;
    len++;
}

void push_back(int x){
    deque[tail++] = x;
    len++;
}

void pop_back(){
    int back = deque[--tail];
    len--;
    cout << back << endl;
}

void pop_front(){
    int front = deque[head++];
    len--;
    cout << front << endl;
}

void operation(string op){
    if (op == "push_front"){
        int x;
        cin >> x;
        push_front(x);
    } else if (op == "push_back"){
        int x;
        cin >> x;
        push_back(x);
    } else if (op == "pop_front"){
        if (empty()) {
            cout << -1 << endl;
            return;
        }
        pop_front();
    } else if (op == "pop_back"){
        if (empty()) {
            cout << -1 << endl;
            return;
        }
        pop_back();
    } else if (op == "size"){
        cout << len << endl;
    } else if (op == "empty"){
        cout << empty() << endl;
    } else if (op == "front"){
        if (empty()) {
            cout << -1 << endl;
            return;
        }
        cout << deque[head] << endl;
    } else if (op == "back"){
        if (empty()) {
            cout << -1 << endl;
            return;
        }
        cout << deque[tail-1] << endl;
    }
}

int main (){

    int N;
    cin >> N;

    while(N--){
        string op;
        cin >> op;
        operation(op);
    }
    
}