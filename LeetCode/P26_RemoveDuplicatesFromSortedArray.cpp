class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        if (nums.size() == 0) return 0; // 비어있는 벡터가 들어오면 그냥 0을 반환
        for (int j = 0 ; j < nums.size() ; j++){
            if (nums[j] != nums[i]){
                nums[i+1] = nums[j];
                i++
            }
        }
        return i+1;
    }
};