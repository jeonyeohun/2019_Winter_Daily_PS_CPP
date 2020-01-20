#include <iostream>
#include <vector>

using namespace std;

int main (){
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        vector<unsigned int> cnt;
        while(N--){
            unsigned int num;
            cin >> num;
            cnt.push_back(num);
        }

        int result = cnt[0];
        for (int i = 1 ; i < cnt.size() ; i++){
            result = result ^ cnt[i];
        }
        int i = 1;
        cout << "Case #" << i++ << "\n";
        cout << result;
    }

}
