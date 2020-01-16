#include <iostream>

using namespace std;

int main (){
    int cnt = 0;
    int price;
    cin >> price;

    while(price > 0){
        cnt += price/7;
        price %= 7;
        cnt += price/5;
        price %= 5;
        cnt += price/2;
        price %= 2;
        cnt += price/1;
        price %= 1;
    }

    cout << cnt;
}