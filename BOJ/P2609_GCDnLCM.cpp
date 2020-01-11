#include <iostream>

using namespace std;

int GCD(int n1, int n2){
    if(n2 != 0) return GCD(n2, n1%n2);
    return n1;
}

int LCM(int n1, int n2){
    return n1*n2 / GCD(n1, n2);
}


int main (){
    int n1, n2;
    cin >> n1 >> n2;
    cout << GCD(n1, n2) << "\n" << LCM(n1, n2);
    return 0;
}