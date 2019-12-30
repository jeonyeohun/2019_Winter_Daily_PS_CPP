class Solution {
public:
   vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>n1, n2;
        vector<int>result;
        n1.assign(nums1.begin(), nums1.end());
        n2.assign(nums2.begin(), nums2.end());
        int cnt = 0;
        for(int i = 0 ; i < n1.size() ; i++){
            for(int j = 0 ; j < n2.size() ; j++){
                if (n1[i]==n2[j]){
                    result.push_back(n1[i]);
                    n1.erase(n1.begin()+i);
                    i--;
                    n2.erase(n2.begin()+j);
                    break;
                }
            }
        }
        
        return result;
    }
};