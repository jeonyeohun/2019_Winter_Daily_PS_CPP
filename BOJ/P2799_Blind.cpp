#include <iostream>
#include <vector>
#include <string>

using namespace std;

 

int arr[5];
vector<string> v;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M, N;
    cin >> M >> N;
    
    v.resize(5 * M + 1); // 벡터 크기를 입력된 크기로 재조정
    for (int i = 0; i < 5 * M + 1; i++)
        cin >> v[i];
        for (int i = 0; i < 5 * M + 1; i++){
            bool checked = false; // 창문 윗줄 판정
            for (int j = 0; j < v[i].size(); j++){
                if (v[i][j] == '.'){
                    checked = true;
                    arr[0]++;
                    j += 3;
                }        
                else if (v[i][j] == '*'){
                    checked = true;
                    int k = 0;
                    while (1){
                        k++;
                        if (v[i + k][j] != '*') break;
                    }
                    arr[k]++;
                    j += 3;
                    }
                 }
                 if (checked) i += 3;
        }

        for (int i = 0; i < 5; i++)

                 cout << arr[i] << " ";

        cout << "\n";

        return 0;

}