#include <cstdio>
#include <stack>

using namespace std;

int main (){
    int K;
    stack<int> stk;
    scanf("%d", &K);

    while(K--){
        int n;
        scanf("%d", &n);
        if (n == 0) stk.pop();
        else stk.push(n);
    }

    int result = 0;
    while(stk.size()){
        result += stk.top();
        stk.pop();
    }

    printf("%d", result);

}