#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool isMax (string n1, string n2);
string addAB (string str1, string str2);
string fibonacci(int n);
int main (){
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}

bool isMax (string n1, string n2){
    if (n1.size() > n2.size()) return true;
    else if (n1.size() < n2.size()) return false;
    else{
        for (int i = 0 ;  i < n1.size() ; i++){
            if(n1[i] > n2[i]) return true;
            else if(n1[i] < n2[i]) return false;
        }
    }
    return true;
}

string fibonacci(int n){
    string result;
    string prev = "1", prevprev = "0";
    if (n == 0) result = "0";
    if (n == 1) result = "1";
    for (int i = 2 ; i <= n ; i++){
        result = addAB(prevprev, prev);
        prevprev = prev;
        prev = result;
    }
    return result;
}

string addAB (string str1, string str2){
    int c_out = 0;
    string result;

    while(true){
        string n1, n2;
        if (str1.empty()) n1 = "0";
        else n1 = str1.at(str1.size()-1);
        
        if (str2.empty()) n2 = "0";
        else n2 = str2.at(str2.size()-1);
        
        int num = c_out + stoi(n1) + stoi(n2);
        c_out = 0;
        
        if(num >= 10) c_out = num/10;
        result+=to_string(num%10);
        
        if (!str1.empty()) str1.pop_back();
        if (!str2.empty()) str2.pop_back();
        if (str1.empty() && str2.empty()) break;
    }
    if (c_out > 0) result+=to_string(c_out);
    
    reverse(result.begin(),result.end());

    return result;
}
