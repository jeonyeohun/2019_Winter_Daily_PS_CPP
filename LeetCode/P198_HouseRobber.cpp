class Solution {
public:
    vector<int> memo;
    int s (vector<int> nums, int n){
        if (n < 0) return 0;
        if(memo[n] >= 0) return memo[n];
        int result = max(s(nums, n-2) + nums[n], s(nums, n-1));
        memo[n] = result;
        return result;
    }
    int rob(vector<int>& nums) {  
        memo.resize(nums.size(), -1);
        return s(nums, nums.size()-1);
    }
};