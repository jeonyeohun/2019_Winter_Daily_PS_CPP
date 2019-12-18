#include <iostream>
#include <vector>
using namespace std;

long int fac(long int n);
int main (){
    long int T, k, n;
    long int apt[15][14] = {0};

    // 전체 배열에 인원 수 맵핑하기 //
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 14 ; j++){
            if (i == 0) apt[i][j] = j+1;
            else{
                int sum = 0;
                for(int s = 0 ; s <= j  ; s++){
                    sum += apt[i-1][s];
                    apt[i][j] = sum;
                }
            }
        }
    }
    cin >> T;
    vector<long int> result;
    // 테스트케이스를 받고 그만큼 결과 벡터에 저장 //
    for (int i = 0 ; i < T ; i++){
        cin >> k >> n;
        result.push_back(apt[k][n-1]);
    }
    for (long int r : result){
        cout << r << endl;
    }
}
