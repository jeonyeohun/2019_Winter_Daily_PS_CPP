#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string dp [500] = {"0" , "1"};
bool isMax (string n1, string n2);
string addAB (string str1, string str2);
void fibonacci(int n);
int main (){
    string  a, b;
    int i = 1;
    
    fibonacci(500);

    while(true){
        cin >> a >> b ;
        if (a == "0" && b == "0") break;
        int cnt = 0;

        for (int j = 2 ; j < 500 ; j++){
            if (isMax(dp[j], a) && isMax(b, dp[j])) cnt++;
        } 
        printf("%d\n", cnt);
    }

    
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

void fibonacci(int n){
    for(int i=2; i<=n; i++){
        dp[i] = addAB(dp[i-1], dp[i-2]);
    }
}

string addAB (string str1, string str2){
    int c_out = 0;
    vector<int> result;
    string s;

    while(true){
        string n1, n2;
        if (str1.empty()) n1 = "0";
        else n1 = str1.at(str1.size()-1);
        
        if (str2.empty()) n2 = "0";
        else n2 = str2.at(str2.size()-1);
        
        int num = c_out + stoi(n1) + stoi(n2);
        c_out = 0;
        
        if(num >= 10) c_out = num/10;
        result.insert(result.begin(), num%10);
        
        if (!str1.empty()) str1.pop_back();
        if (!str2.empty()) str2.pop_back();
        if (str1.empty() && str2.empty()) break;
    }
    if (c_out > 0) result.insert(result.begin(), c_out);
    
    for (int i = 0 ; i < result.size() ; i++){
        s.append(to_string(result[i]));
    }
    return s;
}
