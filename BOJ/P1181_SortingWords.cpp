#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main (){

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);


    int N, maxlen = 0;
    cin >> N;

    vector<string> words;
    vector<string> result;

    while(N--){
        string w;
        cin >> w;
        if (!words.empty()){
            if(find(words.begin(), words.end(), w) != words.end()) continue; // 똑같은 단어가 이미 벡터안에 있으면 건너뛴다.
        }
        words.push_back(w);
        if (w.size() > maxlen) maxlen = w.size(); // 최대 단어 길이 저장
    }    

    for (int i = 1 ; i <= maxlen ; i++){ // 길이 1부터 길이 N까지에 해당하는 단어들을 하나씩 뽑기
        int start=-1;
        for(int j = 0 ; j < words.size() ; j++){ 
            if (words[j].size() == i){ 
                if (start == -1) start = result.size(); // 길이 N에 해당하는 첫 단어가 나왔을 때 그 시작인덱스를 저장하자. 
                result.push_back(words[j]);
            }
        }
        if (start == -1) continue; // start 가 -1이면 해당 단어길이에 해당되는 단어가 없으므로 건너뛰기
        sort(result.begin()+start, result.end()); // 길이 N에 대한 단어들을 정렬 
    }

    for (string s : result){
        cout << s << endl;
    }
}