#include <cstdio>
#include <set>

using namespace std;

int MAX = 10;

int main(){
    set<int> s;
    while(MAX--){
        int n;
        scanf("%d", &n);
        s.insert(n%42);
    }

    printf("%lu\n", s.size());
    
    return 0;

}