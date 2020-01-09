#include <vector>
#include <iostream>

using namespace std;

vector<int> results;

bool isPrime (int sum){
    for (int i = 2 ; i < sum ; i++){
        if (sum % i == 0) return false;
    }
    return true;
}

int DFS(int pos, vector<int> nums){
    int sum = 0;
    if (results.size() == 3){
        for (int i = 0 ; i < 3 ; i++) sum += results[i];
        return isPrime(sum);
    }

    int ret = 0;
    for (int i = pos ; i < nums.size() ; i++){
            results.push_back(nums[i]);
            ret += DFS(i+1, nums);
            results.pop_back();
    }
    return ret;
}

int solution(vector<int> nums) {
    int answer = -1;
    answer = DFS(0, nums);

    return answer;
}