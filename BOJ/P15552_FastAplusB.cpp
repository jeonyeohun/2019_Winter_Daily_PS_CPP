#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t, a, b;
    cin >> t;

    while(t--){
        cin >> a >> b;
        cout << a+b << "\n";
    }
    return 0;
    
}