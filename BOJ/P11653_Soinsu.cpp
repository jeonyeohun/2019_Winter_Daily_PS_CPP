#include<iostream>

using namespace std;

int main (){
    int N;
    cin >> N;

    for (int i = 2 ; i <= 10000000 ; i++){
        if(N == 1) break;
        if(N%i == 0){
            cout << i << "\n";
            N /= i;
            i--;
        }
    }
}