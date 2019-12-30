#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int score = 0;
        int consc = 1;
        for (int i = 0 ; i < str.size() ; i++){
            if(str.at(i) == 'O'){
                score += (1*consc);
                consc++;
            }
            else consc = 1;
        }
        cout << score << "\n";
    }
    return 0;
}