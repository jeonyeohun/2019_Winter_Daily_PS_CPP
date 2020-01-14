class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end(), greater<int>());
        
        for (int i = 0 ; i < A.size()-2 ; i++){
            for (int j = i+1 ; j < A.size()-1 ; j++){
                for (int k = j+1 ; k < A.size() ; k++){
                    if (A[i] < A[j]+A[k]) return A[i]+A[j]+A[k];
                    else break;
                }
            }
        }
        return 0;
    }
};