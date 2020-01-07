#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main (){
    int N;
    vector<string> song{"baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby", "sukhwan"};
    cin >> N;

    int itr = N/14;
    int idx = N%14-1;
    if (idx < 0) idx = 13;
    

    if (song[idx][0] == 't'){
        if (idx % 2 == 0 && itr >= 3){
            cout << "tu+ru*" << itr+2;        
            return 0;
        }
        else if(idx % 2 == 1 && itr >= 4){
            cout << "tu+ru*" << itr+1;        
            return 0;
        }
        for (int i = 0 ; i < itr ; i++)
            song[idx] += "ru";
        cout << song[idx];
        return 0;
    }
    cout << song[idx];
    return 0;    
}