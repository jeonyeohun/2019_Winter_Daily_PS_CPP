class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> v; // 페어 형태의 스택 선언 first는 문자, second는 해당 문자가 몇번 나왔는지 저장
        string result = "";
        v.emplace(make_pair('0', 0));
        
        for (auto c : s){
            if(v.top().first == c && v.top().second + 1 == k){ // 맨위에 있는 문자가 s에서 방금 꺼낸 문자와 같으면서 그 갯수가 k-1이라면 방금 꺼낸것만 넣으면 k개가 되니까 다 꺼내야된다.
                while(!v.empty()  && v.top().first == c){ // 스택이 비어있지 않고 맨위에 방금 나온 문자가 나와있을 때 동안은
                    v.pop(); //스택도 계속 pop하고 
                    result.pop_back(); // 결과 스트링도 계속 pop
                }
            }
            else{
                v.emplace(make_pair(c, v.top().second * (v.top().first == c) + 1)); // 방금 꺼낸 문자가 top과 다르거나 k개가 완성이 안돠는 경우에는 그냥 위에 올리면 되는데 현재 first에 있는 문자와 꺼낸 문자를 비교해서 같은면 second의 값을 하나 올려주고 다르면 1을 넣어준다.
                result+=c;
            }
        }
        
        return result;
    }
};