class Solution {
public:
    
    bool checkRecord(string s) {
        int acnt = 0;
        for (int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'A') acnt++;
            if(s[i] == 'L'){
                int cnt = 0;
                while(s[i] == 'L' && i < s.size()) {
                    ++i;
                    cnt++;
                }
                i-=1;
                if (cnt > 2) return false;
            }
            if (acnt > 1) return false;
        }
        
        
        
        return true;
    }
};