class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        int N = nums.size()/2+nums.size()%2;
        for(int i = 1 ; i <= N ; i++){
            int ns = nums.size();
            int temp = nums[ns-1];
            nums.insert(nums.begin()+N-i, temp);
            nums.pop_back();
        }
    }
};