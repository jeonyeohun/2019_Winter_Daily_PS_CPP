#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main (){
    string str1, str2;
    vector <int> result;
    int c_out = 0;
    
    cin >> str1 >> str2;
    
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
        cout << result[i];
    }
    return 0;
}
