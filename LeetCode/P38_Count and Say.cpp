class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1"; // 1 이 들어오면 바로 리턴
        string result = "1";
        n-=1; // 1을 제외하기 때문에 반복횟수를 하나 줄여줘야한다.
        
        while(n--){ // 총 n-1번 반복해서 n번째 값을 구할거야
            vector<pair<int, int>> v; // int 페어를 가지는 벡터를 만들고
            for (int i = 0 ; i < result.size() ; i++){
                int cnt = 0;
                for (int j = i ; j < result.size() ; j++){
                    if (result[i] == result[j]) cnt++; // i번째 값이 연달아 몇번나왔는지 세기
                    else break;
                }
                v.emplace_back(make_pair(result[i]-'0', cnt)); // 페어에 첫번째에 스트링에서 읽은 문자 하나를 int로 바꿔서 넣고 페어의 두번째에는 그 문자가 나온 횟수를 넣어준다.
                i+=cnt-1; // 연달아 나온애들은 여러번 검사할 필요가 없으니까 건너뛰어준다.
            }
            string cur;
            // 여기까지 왔으면 result에 있는 글자들이 총 몇번씩 나왔는지 세트로 벡터에 저장되어있는 상태 
            for (auto it = v.begin() ; it != v.end() ; it++){
                cur += to_string(it->second) + to_string(it->first); // 하나씩 꺼내서 secondfirst 형태로 앞에서부터 출력해주면 끝
            }
            result = cur; // result 를 방금 구한 값으로 구해야지 n번 반복하면서 result가 계속 바뀐다.
        }
        return result;
    }
};