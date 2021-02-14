#include <cstdio>
#include <list>

using namespace std;

int main (){
    int N, K, idx = 0;
    list<int> numbers;
    scanf("%d %d", &N, &K);

    for (int i = 1 ; i <= N ; i++){
        numbers.push_back(i);
    }

    auto iter = numbers.begin();
    int count = 1;
    int answer[N];

    while(!numbers.empty()){
        if(count == K){
            answer[idx++] = *iter;
            iter = numbers.erase(iter);
            count = 0;
            iter--;
        }
        iter++;
        if (iter == numbers.end()) iter = numbers.begin();
        count++;
    }

    printf("<");
    for (int i = 0 ; i < N ; i++){
        if (i == N-1) printf("%d>", answer[i]);
        else printf("%d, ", answer[i]);
    }
    
}
