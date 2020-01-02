class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int minsize = 100000;
        
        if(strs.empty()) return "";
        
        // 최소 길이 구하기
        for (int i = 0 ; i < strs.size() ; i++){
            if (minsize > strs[i].size()) minsize = strs[i].size();
        }
        
        // longest common prefix 검사
        for(int i = 0 ; i < minsize ; i++){
            char prefix = strs[0][i];
            for (int j = 0 ; j < strs.size() ; j++){
                if (strs[j][i] != prefix) return result;
            }
            result.push_back(prefix);
        }
        return result;
    }
};