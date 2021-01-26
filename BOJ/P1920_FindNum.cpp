#include <cstdio>
#include <algorithm>

using namespace std;

int arr [100001]; 

bool binarySearch (int size, int target){
    int head = 0;
    int tail = size - 1;
    int mid = 0;

    while (head <= tail) {
        mid = (head + tail) / 2;

        if (arr[mid] == target){
            return true;
        }
        else if (arr[mid] > target){
            tail = mid - 1;
        }
        else if (arr[mid] < target){
            head = mid + 1;
        }
    }
    return false;
}

int main (void){
    int N, M;
    scanf("%d", &N);

    for (int i = 0 ; i < N ; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+N);

    scanf("%d", &M);
    while(M--){
        int target;
        scanf("%d", &target);

        if(binarySearch(N, target)){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
}