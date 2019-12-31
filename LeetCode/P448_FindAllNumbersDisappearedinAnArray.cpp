class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> result(nums.size(), true); // 마킹용 벡터
        vector<int> v;
        
        for (int i = 0 ; i < nums.size() ; i++){
            int n = nums[i]-1;
            result[n] = false;
        }
        
        for (int i = 0 ; i < result.size() ; i++){
            if (result[i] == true) v.push_back(i+1); // 마킹이 안되어 있는 인덱스만 찾아서 벡터에 집어넣기
        }
        
        return v;
    }
};