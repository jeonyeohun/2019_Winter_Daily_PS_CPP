#include <iostream>
#include <math.h>

using namespace std;

int main(){
    float r;
    cin >> r;
    cout << fixed;
    cout.precision(6); // 소수점 고정

    cout << M_PI * pow(r, 2) << endl;
    cout << 2 * pow(r, 2) << endl;

    return 0;
}