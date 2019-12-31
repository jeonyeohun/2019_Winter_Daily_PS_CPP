class Solution {
public:
    string intToRoman(int num) {
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> n = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string result = "";
        
        for (int i = 0 ; i < n.size() ; i++){
            if(num/n[i]>0){
                for (int j = 0 ; j < num/n[i] ; j++){
                    result+=roman[i];
                }
                num %= n[i];
            }
        }
        return result;
    }
};