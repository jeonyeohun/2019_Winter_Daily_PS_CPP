class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string vS, vT;
        
        for (int i = 0 ; i < S.size() ; i++){
            if(isalpha(S[i])) vS.push_back(S[i]);
            else if(!vS.empty()) vS.pop_back();
        }
        for (int i = 0 ; i < T.size() ; i++){
            if(isalpha(T[i])) vT.push_back(T[i]);
            else if(!vT.empty()) vT.pop_back();
        }
        
        if(!vS.compare(vT)) return true;
        else return false;
    }
};