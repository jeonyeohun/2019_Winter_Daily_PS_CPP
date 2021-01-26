#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int queue [100001];
int head = 0;
int tail = 0;
int len = 0;


int empty(){
    if (len == 0) return 1;
    else return 0;
}

void push (){
    int input;
    cin >> input;
    queue[tail++] = input;
    len++;
}

int pop(){
    if (empty()) return -1;

    int front = queue[head++];
    len--;
    return front;
}

int size(){
    return len;
}

int front(){
    if (len == 0) return -1;
    else return queue[head];
}

int back(){
    if (len == 0) return -1;
    else return queue[tail-1];
}

int main (){
    int operations;
    scanf("%d", &operations);
    while(operations--){
        string op;
        cin >> op;
        if (op == "push") push();
        else if (op == "pop") printf("%d\n", pop());
        else if (op == "size") printf("%d\n", size());
        else if (op == "empty") printf("%d\n", empty());
        else if (op == "front") printf("%d\n", front());
        else printf("%d\n", back()); 
    }
}