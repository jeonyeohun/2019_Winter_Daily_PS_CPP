class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even = 0;
        int odd = 1;
        vector<int> v(A.size());
        for (int i = 0 ; i < A.size() ; i++){
            if (A[i]%2 == 0) {
                v[even] = A[i];
                even += 2;
            }
            else {
                v[odd] = A[i];
                odd += 2;
            }
        }
        return v;
    }
};