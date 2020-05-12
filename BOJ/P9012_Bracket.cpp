#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int main (){
    int T;
    scanf("%d", &T);
    

    while(T--){
        char str[51];
        stack<char> stk;
        scanf("%s", str);
      
        for (int i = 0 ; i < (int)strlen(str) ; i++){
            if (stk.empty() && str[i] == ')') {
                stk.push('1');
                break;
            }
            if (str[i] == '(') stk.push(str[i]);
            else stk.pop();
        }

        if (stk.size() > 0) printf("NO\n");
        else printf("YES\n");
    }
}
