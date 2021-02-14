#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n, idx = 0;
    stack<int> stk;
    vector<char> answer;
    vector<int> sequence;
    scanf("%d", &n);
    
    while(n--){
        int x; 
        scanf("%d", &x);
        sequence.push_back(x);
    }

    for (int i = 1 ; i <= sequence.size() ; i++){
        stk.push(i);
        answer.push_back('+');

        while(!stk.empty() && stk.top() == sequence[idx]){
            printf("    %d\n", stk.top());
            stk.pop();
            answer.push_back('-');
            idx++;
        }

        
    }

    if (!stk.empty()){
        printf("NO\n");
    }
    else{
        for (auto ans : answer){
            printf("%c\n", ans);
        }
    }   
}
