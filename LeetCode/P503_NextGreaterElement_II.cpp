class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result;
        
        for (int i = 0 ; i < nums.size() ; i++){
            int j = i+1;
            for ( ; j != i ; j++){
                if (j >= nums.size()) j = 0;
                if (j == i) break;
                if (nums[j] > nums[i]) {
                    result.push_back(nums[j]);
                    break;
                }
            }
            if (j == i) result.push_back(-1);
            
        }
        return result;
    }
};