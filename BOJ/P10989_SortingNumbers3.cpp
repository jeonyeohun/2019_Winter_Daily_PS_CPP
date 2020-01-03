#include<iostream>
#include<vector>

using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> outarr (10001, 0);

    while(N--){
        int n;
        cin >> n;
        // 입력을 받을 때마다 배열에 카운팅 개수 늘려주기
        outarr[n]++;
    }

    // 여기 까지 왔을 때는 각 배열의 인덱스에 해당하는 값이 몇번나왔는지 배열에 들어가 있다.
    for (int i = 0 ; i < outarr.size() ; i++){
        while(outarr[i] != 0){ // 카운팅이 0이 될 때까지 출력
            cout << i << "\n";
            outarr[i]--;
        }
    }

    return 0;
}
