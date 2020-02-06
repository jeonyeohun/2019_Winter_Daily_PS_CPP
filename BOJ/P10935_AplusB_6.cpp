#include <iostream>
#include <string>

using namespace std;

int main (){
    string s;
    int N;
    
    cin >> N;
    
    while(N--){
        cin >> s;
        cout << (s[0] - '0') + (s[2] - '0') << "\n"; 
    }

    return 0;
}