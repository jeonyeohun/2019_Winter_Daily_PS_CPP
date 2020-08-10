#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<char> result;
bool visited [10000];

int D (int n){
    return n > 9999 ? n % 10000 : n * 2;
}

int S (int n){
    return n == 0 ? n = 9999 : n - 1;
}

int L (int n){
    return (n % 1000) * 10 + (n / 1000);
}

int R (int n){
    return (n % 10) * 1000 + (n / 10) ; 
}

void bfs (int A, int B){
    char op [] = {'D', 'S', 'R', 'L'};
    queue <int> nums;
    nums.push(A);

    while(!nums.empty()){
        int newA = nums.front();
        nums.pop();
        if (newA == B) {
            for(int i = 0 ; i < result.size() ; i++){
                printf("%c",result[i]);
            }
            printf("\n");
            return;
        }

        if(visited[newA]) continue;
        for (int i = 0 ; i < 4 ; i++){
            switch(op[i]){
                case 'D' :
                    nums.push(D(newA));
                    result.push_back('D');
                    visited[result.back()] = true;
                    break;
                case 'S' :
                    nums.push(S(newA));
                    result.push_back('S');
                    visited[result.back()] = true;
                    break;
                case 'R' :
                    nums.push(R(newA));
                    result.push_back('R');
                    visited[result.back()] = true;
                    break;
                case 'L' :
                    nums.push(L(newA));
                    result.push_back('L');
                    visited[result.back()] = true;
                    break;
            }
        }
    }

    result.pop_back();
}

int main (){
    int T, A, B;
    scanf("%d", &T);

    while(T--){
        scanf("%d %d", &A, &B);
        bfs(A, B);
    }
}