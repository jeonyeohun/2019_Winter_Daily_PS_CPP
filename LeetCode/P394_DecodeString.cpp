class Solution {
public:
    string decodeString(string s) {
        vector<int> numbers;
        vector<string> alphas;
        string result = "";
        
        for (int i = 0 ; i < s.size() ; i++){
           if(isdigit(s[i])) {
               string num;
               while(s[i] != '['){ // "[" 가 나올때까지 나온 문자열을 합쳐서 정수로 만들기
                   num.push_back(s[i++]);
               }
                numbers.push_back(stoi(num));
                alphas.push_back("[");
            }
            else if (s[i] == ']'){ // "]" 를 만나면 앞에 있는 "[" 까지의 문자들을 합쳐서 문자열로 만든다.
                string temp;
                while(alphas.back().compare("[")){
                    temp.insert(temp.begin(), alphas.back().begin(), alphas.back().end());
                    alphas.pop_back(); // 문자열에 합친 문자 없애기
                }
                alphas.pop_back(); // alphas에서 "[" 없애기 
                
                string r;
                
                for (int j = 0 ; j < numbers.back() ; j++) r+=temp; // numbers에 들어있는 수 만큼 반복해서 문자열 만들기
                
                alphas.push_back(r); // 합쳐진 문자열을 다시 스택에 넣는다.
                numbers.pop_back(); // 사용된 숫자는 지우기
            }
            else{
                string a;
                a.push_back(s[i]);
                alphas.push_back(a);
            }
        }
        for (string str : alphas) result += str; // 여기까지 오면 스택에는 합쳐진 문자열 그룹들만 남는다. 얘네들을 합쳐서 또 새로운 문자열로 만들고 출력
        
        return result;
    }
    
};