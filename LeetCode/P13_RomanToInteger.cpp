class Solution {
public:
    int romanToInt(string s) {
        vector<string> roman = {"I", "V", "X", "L", "C", "D", "M", "IV", "IX", "XL", "XC", "CD", "CM"};
        int decim [] = {1, 5, 10, 50, 100, 500, 1000, 4, 9, 40, 90, 400, 900};
        int result = 0;
        for(int i = 0 ; i < s.size() ; i++){
            string c;
            c = s[i];
            
            if(s[i] == 'C' || s[i] == 'X' || s[i] == 'I') c += s[i+1];
            
            if (find(roman.begin()+7, roman.end(),c) == roman.end()) c = s[i];
            else i++;
            
            
            for (int j = 0 ; j < roman.size() ; j++){
                if (c.compare(roman[j]) == 0){
                    result += decim[j];
                    cout << c << decim[j] <<endl;
                }
            }
        }
        return result;
    }
};