class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(int i = 0 ; i < nums1.size() ; i++){
            auto iter = find(nums2.begin(), nums2.end(), nums1[i]); // nums2 에서 nums1[i] 찾기
            if (iter == nums2.end()) result.push_back(-1); // 검색된 아이템이 없으면 -1 push하고 끝 
            else{
                auto it = iter;
                for (; it != nums2.end(); it++){ // 검색된 위치부터 끝까지 돌면서 
                    if(*it > nums1[i]) { // nums1[i] 보다 더 큰 값이 있는지 찾는다 
                        result.push_back(*it); // 있으면 push하고 반복 탈출 
                        break;
                    }
                }
                if (it == nums2.end()){ // 여기까지 왔는데 it에 num2.end() 가 있으면 break가 안됐다는 뜻이니까 다음으로 큰 값이 없다는 것.
                    result.push_back(-1); // -1 push 
                }
            }
        }
        return result;
    }
};