#include <cstdio>
#include <algorithm>

int cards[500001];

using namespace std;

bool binarySearch(int size, int target){
    int head = 0;
    int tail = size - 1;
    int mid;

    while(head <= tail){
        mid = (head + tail) / 2;
        if (cards[mid] == target) return true;
        else if (cards[mid] < target) head = mid + 1;
        else if (cards[mid] > target) tail = mid - 1;
    }

    return false;
}

int main (){
    int N;
    scanf("%d", &N);

    for (int i = 0 ; i < N ; i++){
        scanf("%d", &cards[i]);
    }

    sort(cards, cards+N);
    
    int M;
    scanf("%d", &M);

    while(M--){
        int target;
        scanf("%d", &target);

        if(binarySearch(N, target)) printf("1 ");
        else printf("0 ");
    }
}