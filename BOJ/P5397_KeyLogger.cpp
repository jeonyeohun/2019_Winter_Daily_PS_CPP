#include <iostream>
#include <ctype.h>
#include <list>
#include <string>
using namespace std;

int main (){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    
    while(t--){
        string c; cin >> c;
        list <char> pw;
        list<char>::iterator iter = pw.begin();
        long int clen = c.size();
        
        for(int i = 0 ; i < clen ; i++){
            if (c[i] == '<' && iter != pw.begin() && !pw.empty()) iter--;
            else if (c[i] == '>' && iter != pw.end() && !pw.empty()) iter++;
            else if (c[i] == '-' && !pw.empty()) {
                if (iter != pw.begin()) iter = pw.erase(--iter);
            }
            else if (isdigit(c[i]) || isalpha(c[i])){
                if (pw.empty()) pw.push_back(c[i]);
                else pw.insert(iter, c[i]);
            }
            
        }
        for (char c : pw){
            cout << c;
        }
        cout << "\n";
        pw.clear();
    }
    return 0;
}

