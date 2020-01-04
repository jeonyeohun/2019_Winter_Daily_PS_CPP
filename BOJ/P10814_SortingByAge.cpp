#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main (){
    int N;
    cin >> N;

    multimap<int, string> data;
    while(N--){
        int age;
        string name;
        cin >> age >> name;

        data.insert(pair<int, string>(age, name)); // 멀티 맵은 넣으면 first기준으로 정렬되고 같은 값은 나중에 들어온 값이 뒤로 간다.
    }

    for (map<int, string>::iterator iter = data.begin() ; iter != data.end() ; iter++){
        cout << (*iter).first << " " << (*iter).second << "\n";
    }
}
