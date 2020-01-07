class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> v;
        string temp;
        for (int i = 0 ; i < s.size() ; i++){
            string str(1, s[i]);
            if (s[i] == ')'){
                while(v.back() != "("){
                    temp += v.back();
                    v.pop_back();
                }
                s.replace(i-temp.size()-1, temp.size()+2, temp);
                v.pop_back();
                i = v.size()-1;
            }
            else{
                v.push_back(str);
            }
            temp.clear();
        }
        return s;
    }
};