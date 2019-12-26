#include <set>
#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    set<string> strset;
    cin >> s;
    
    set<string>:: iterator iter;

    for (int i = 0 ; i < s.size() ; i++){
        for (int j = 1 ; j <= s.size()-i ; j++){
            string temp = s.substr(i, j);
            strset.insert(temp);
        }
    }
    cout << strset.size() << endl;
}
