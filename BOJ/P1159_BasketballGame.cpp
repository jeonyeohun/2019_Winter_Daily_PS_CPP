#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int t=0;
    bool isNew = true;
    vector<string> names;
    vector<int> cnt;
    
    cin >> t;
    while(t--){
        string temp;
        cin >> temp;
        temp = temp[0];
        
        if(names.empty()){
            names.push_back(temp);
            cnt.push_back(1);
            isNew = false;
        }
        else{
            for (int i = 0 ; i < names.size() ; i++){
                isNew = true;
                if (temp.compare(names[i])==0) {
                    cnt[i]++;
                    isNew = false;
                    break;
                }
            }
        }
        if (isNew){
            names.push_back(temp);
            cnt.push_back(1);
        }
    }
    bool flag = false;
    vector <string> list;
    for (int i = 0 ; i < cnt.size() ; i++){
        if (cnt[i] >= 5) {
            list.push_back(names[i]);
            flag = true;
        }
    }
    if (flag == false){
        cout << "PREDAJA" << endl;
    }
    else{
        sort(list.begin(), list.end());
        for (string s : list) cout << s;
    }
    return 0;
}
