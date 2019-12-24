#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

bool isClean(vector<vector<int> > &arr, int m, int n);
int main (){
    int t;
    scanf("%d", &t);
    while(t--){
        int M, N;
        scanf("%d %d", &N, &M);
        vector<vector<int> > arr(N, vector<int>(M, 0));
        for (int i = 0 ; i < N ; i++){
            for (int j = 0 ; j < M ; j++){
                scanf("%d", &arr[i][j]);
            }
        }

        bool result = isClean(arr, M, N);
        if (result) printf("YES");
        else printf("NO");

        for (int i = 0 ; i < N ; i++){
            arr[i].clear();
        }
        arr.clear();
    }
    
    return 0;
}

bool isClean(vector<vector<int> > &arr, int m, int n){
    bool result = true;
    for (int i = 0 ;  i < n ; i++){
        for (int k = i+1 ; k < n ; k++){
            for (int j = 0 ; j < m ; j++){
                for (int l = j+1 ; l < m ; l++){
                    if (arr.at(i)[j] + arr.at(k)[l] > arr.at(i)[l] + arr.at(k)[j]){
                        result = false;
                    }
                }
            }
        }
    }
    return result;
}
