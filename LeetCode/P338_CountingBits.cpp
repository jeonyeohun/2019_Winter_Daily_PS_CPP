class Solution {
public:
    bool isPow(int a){
        int n = 1;
        int i = 1;
        while(n < a) n = 1 << i++;
        if (n == a) return true;
        else return false;
    }
    
    vector<int> countBits(int num) {
        vector<int> dp {0, 1};

        int j = 0;
        for (int i = 2 ; i <= num ; i++){
            if (isPow(i)) j = 0;
            dp.push_back(dp[j++]+1);
        }
        
        vector<int> result;
        for (int i = 0 ; i <= num ; i++){
            result.push_back(dp[i]);
        }
        return result;
    }
};