class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int cnt=1;
        string A_copy = A;
        while(true){
            if(A_copy.find(B) != -1) break;
            if(A_copy.size() > B.size()+A.size()) return -1;
            cnt++;
            A_copy+=A;
            
        }
        return cnt;
    }
};