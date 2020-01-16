#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main (){
    string poly;
    cin >> poly;
    vector<string> tokens;
    
    
    while(!poly.empty()){
        int end;
        string token;
        for (end = 1 ; end < poly.size() ; end++){
            if (poly[end] == '-' || poly[end] == '+') break;
        }
        token = poly.substr(0, end);
        
        tokens.push_back(token);
        poly.erase(0, end);
    }
    
    string result;
    string op = "";
    for (auto s : tokens){
        //cout << s << endl;
        if (stoi(s) == 0) {
            if (s.size() == 2) op.push_back(s[0]);
            break;
        }
        string num;
        size_t p = s.find("x");
        if (p != string::npos) {
            num = s.substr(0, p);
            int n = stoi(num)/2;
            
            if (abs(n) != 1)result += to_string(n);
            else if (n < 0) result += "-";
            result += "xx";
        }
        else{
            num = s;
            if (num.compare("+1") && num.compare("-1")) result += (num+"x+");
            else {
                result.push_back(num[0]);
                result += "x+";
            }
        }
    }
    
    if (result.back() != '+' && result.size() > 1) result += "+";
    if (!op.empty()) {
        result.pop_back();
        result += (op + "W");
    }
    else result += "W";
    cout << result << endl;
}
