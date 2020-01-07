class Solution {
public:
    string removeDuplicates(string S) {
        auto iter = S.begin();
        while(iter != S.end()){
            if (*iter == *(iter+1)) {
                S.erase(iter);
                S.erase(iter);
                iter = S.begin();
                continue;
            }
            iter++;
        }
        return S;
    }
};