#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;

int q [100001];
int qSize = 0;

void push (int x){
    q[qSize] = x;
    qSize++;
}
int pop(){
    int del = q[qSize-1];
    qSize--;
    return del;
}
int size(){
    return qSize-1;
}
int empty(){
    return qSize-1 < 1 ? 1 : 0;
}
int front(){
    if (empty()) return -1;
    return q[0];
}
int back(){
    if (empty()) return -1;
    return q[qSize-1];
}

int main (){
    int N;
    
    scanf("%d", &N);
    getchar();

    while(N--){
        char op[10];
        fgets(op, sizeof(op), stdin);
        if (!strcmp(op, "push")){
            int x;
            scanf("%d", &x);
            push(x);
        }
        else if (!strcmp(op, "pop")){
            printf("%d\n", pop());
        }
        else if (!strcmp(op, "size")){
            printf("%d\n",size());
        }
        else if (!strcmp(op, "pop")){
            printf("%d\n", empty());
        }
        else if (!strcmp(op, "front")){
            printf("%d\n", front());
        }
        else if (!strcmp(op, "back")){
            printf("%d\n", back());
        }
    }
}