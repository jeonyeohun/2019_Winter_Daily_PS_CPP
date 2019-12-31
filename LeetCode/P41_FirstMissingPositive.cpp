class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        if (nums.empty()) return 1;
        sort(nums.begin(), nums.end());
        
        int c = 0;
        
        for (int i = 0 ; i < nums.size() ; i++){
            if (nums[i] <= 0) c++;
            else break;
        } 

        for(long long i = 1 ; i <= (long long)nums[nums.size()-1]+c ; i++){
            if(find(nums.begin(), nums.end(), i) == nums.end()) return i;
        }
        int result;
        
        if (nums[nums.size()-1]< 0) result = 1;
        else result = nums[nums.size()-1]+1;
        
        return result;
    }
};