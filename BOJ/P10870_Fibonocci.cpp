#include <iostream>

using namespace std;
int fib (int n);
int main (){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

int fib (int n){
    if (n < 2) return n;
    return fib(n-1) + fib(n-2);
}