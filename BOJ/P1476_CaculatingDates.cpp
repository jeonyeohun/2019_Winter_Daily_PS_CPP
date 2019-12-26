#include <iostream> 

using namespace std;

int main(){
    int E, S, M, i=1;
    cin >> E >> S >> M;

    for (;;i++){
        if ((i-E)%15==0 && (i-S)%28==0 && (i-M)%19==0) break;
    }

    cout << i << endl;
}