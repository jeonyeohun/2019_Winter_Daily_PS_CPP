class Solution {
public:
    int romanToInt(string s) {
        vector<string> roman = {"I", "V", "X", "L", "C", "D", "M", "IV", "IX", "XL", "XC", "CD", "CM"};
        int decim [] = {1, 5, 10, 50, 100, 500, 1000, 4, 9, 40, 90, 400, 900};
        int result = 0;
        for(int i = 0 ; i < s.size() ; i++){
            string c;
            c = s[i];
            
            if(s[i] == 'C' || s[i] == 'X' || s[i] == 'I') c += s[i+1]; // C, X, M 이 나오면 일단 다음 문자랑 붙이기
            
            if (find(roman.begin()+7, roman.end(),c) == roman.end()) c = s[i]; // 합쳐서 사용하는 표현들 중 방금 합쳤던 문자가 없으면 붙였던거 떼어버리기
            else i++; // 있으면 커서를 한칸 이동
            
            
            for (int j = 0 ; j < roman.size() ; j++){
                if (c.compare(roman[j]) == 0){
                    result += decim[j]; // 숫자 배열에 이미 맵핑되어 있기 때문에 같은 배열 위치에 있는 숫자를 계속 더한다.
                }
            }
        }
        return result;
    }
};