#include <cstdio>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main (){
    stack<int> stk;
    string op;

    int N;
    scanf("%d", &N);

    while(N--){
        cin >> op;

        if (!op.compare("push")){
            int n;
            scanf("%d", &n);
            stk.push(n);
        }
        else if(!op.compare("top")){
               if (!stk.empty()){
                printf("%d\n", stk.top());    
                continue;
            } 
            printf("-1\n");
        }
        else if(!op.compare("pop")){
            if (!stk.empty()){
                printf("%d\n", stk.top());    
                stk.pop();
                continue;
            } 
            printf("-1\n");
        }
        else if(!op.compare("size")){
            printf("%ld\n", stk.size());
        }
        else if(!op.compare("empty")){
            if (!stk.empty()){
                printf("0\n");
            }
            else{
                printf("1\n");
            }
        }

    }
}