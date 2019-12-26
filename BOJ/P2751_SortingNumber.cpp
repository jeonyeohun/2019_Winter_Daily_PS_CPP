#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main (){
    int t;
    vector <int> nums;
    scanf("%d", &t);
    
    while(t--){
        int n;
        scanf("%d", &n);
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end());

    for(int n : nums){
        printf("%d\n",n);
    }

    return 0;
}
