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
                isNew = true; // 새로운 애가 등장하는지 확인하는 플래그
                if (temp.compare(names[i])==0) { // 중복되는 글자가 나오면 횟수 카운터 올리기
                    cnt[i]++;
                    isNew = false;
                    break;
                }
            }
        }
        if (isNew){
            names.push_back(temp); // 새로 등장하는 애들이 나오면 벡터에 새로 추가해준다.
            cnt.push_back(1);
        }
    }
    bool flag = false;
    vector <string> list;
    for (int i = 0 ; i < cnt.size() ; i++){ // 횟수 카운터가 5가 넘는 애들을 새로운 벡터로 옮기기
        if (cnt[i] >= 5) {
            list.push_back(names[i]);
            flag = true;
        }
    }
    if (flag == false){ // 5 이상인 글자들이 없으면 항복선언
        cout << "PREDAJA" << endl;
    }
    else{
        sort(list.begin(), list.end()); // 알파벳 순으로 정렬해서 출력해야되니까 정렬하고 출력
        for (string s : list) cout << s;
    }
    return 0; 
}
