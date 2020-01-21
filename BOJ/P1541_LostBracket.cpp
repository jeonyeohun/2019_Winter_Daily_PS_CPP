#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int accumulate_till_next(string s){
    string n;
    int total = 0;
    for (int i = 0 ; i < s.size() ; i++){
        if(isdigit(s[i])) n.push_back(s[i]);
        else{
            total += stoi(n);
            n.clear();
        }
    }
    total += stoi(n);
    return total;
}

int main (){
    string s;
    cin >> s;

    vector<int> nums;
    string n;
    for (int i = 0 ; i < s.size() ; i++){
        if(isdigit(s[i])) n.push_back(s[i]);
        else{
            if(!n.empty()){
                nums.push_back(stoi(n));
                n.clear();
            }
            if (s[i] == '-'){
                i++;
                while(s[i] != '-' && i != s.size()){
                    n.push_back(s[i++]);
                }
                nums.push_back(accumulate_till_next(n)*-1);
                n.clear();
                i--;
            }
        }
    }
    if (!n.empty()) nums.push_back(stoi(n));
    cout << accumulate(nums.begin(), nums.end(), 0) << endl;

}
