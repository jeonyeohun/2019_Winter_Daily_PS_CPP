class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        for(int i = 0 ; i < nums1.size() ; i++) s1.insert(nums1[i]);
        for(int i = 0 ; i < nums2.size() ; i++) s2.insert(nums2[i]);
        
        vector<int> result;
        
        for (auto iter = s1.begin() ; iter != s1.end() ; ++iter){
            if (s2.find(*iter) != s2.end()){
                result.push_back(*iter);
            }
        }
        
        return result;
    }
};