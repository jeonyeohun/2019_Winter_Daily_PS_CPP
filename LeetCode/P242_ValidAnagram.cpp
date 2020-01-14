class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end()); // 아나그램은 순서만 다르고 구성하는 알파벳은 동일한 문자열이니까 그냥 정렬해서 비교하면 된다.
        sort(t.begin(), t.end());
        
        return (!s.compare(t));
    }
};