class Solution {
public:
    string addBinary(string a, string b) {
        int c_in = 0;
        int a_start = a.size()-1;
        int b_start = b.size()-1;
        string result;
        while(true){  
            int a2int;
            int b2int;
            (a_start < 0) ? a2int = 0 : a[a_start] == '1' ? a2int = 1 : a2int = 0; // a와 b가 사이즈가 다르면 에러나니까 그거에 대한 예외처리
            (b_start < 0) ? b2int = 0 : b[b_start] == '1' ? b2int = 1 : b2int = 0;
            int sum = c_in + a2int + b2int; // 정수로 바꾼 자리를 더해준다.
            int mod = sum%2; // 현재 자리에 대한 결과
            
            if (sum > 1) c_in = 1; // sum이 2이상이 나오면 carry out이 있는거니까 이 값을 carry in으로 넘겨준다.
            else c_in = 0;   
            
            result.insert(result.begin(), '0'+mod); // 정수를 문자로 변환해서 결과 문자열에 넣는다.
            
            a_start--; // 인덱스 이동
            b_start--;
            
            if (a_start<0 && b_start<0) break; // 더이상 연산할 자리가 없으면 반복 종료
        }
        if (c_in > 0) result.insert(result.begin(), '1'); // 종료했을 때, carry in에 숫자가 들어가 있으면 자릿수가 하나 올라간거니까 이걸 맨앞에 끼워넣어준다.
        return result;
    }
};