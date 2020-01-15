#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp (string a, string b){
    if (a.size() < b.size()) return true;
    else if (a.size() > b.size()) return false;
    else{
        int sumA = 0, sumB = 0;
        for (int i = 0 ; i < a.size() ; i++){
            if(isdigit(a[i])) sumA += (a[i]-'0');
            if(isdigit(b[i])) sumB += (b[i]-'0');
        }
        if (sumA < sumB) return true;
        else if (sumA > sumB) return false;
        else {
            return a < b;
        }
    }

}

int main (){
    int N;
    vector<string> serial;

    cin >> N;
    
    while(N--){
        string str;
        cin >> str;
        
        serial.push_back(str);
    }
    sort(serial.begin(), serial.end(), cmp);

    for (auto s : serial){
        cout << s << "\n";
    }

    return 0;
}