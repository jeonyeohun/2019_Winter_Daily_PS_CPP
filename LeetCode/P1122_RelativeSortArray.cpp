class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt (1001, 0); // 몇번 나왔는지 세기
        vector<int> d; // arr1에는 있는데 arr2에는 없는 값들이 들어가는 벡터
        for (int i = 0 ; i < arr1.size() ; i++){
            if (find(arr2.begin(), arr2.end(), arr1[i]) == arr2.end()) // arr2에서 arr1[i]를 찾아보고 없으면 d에 넣어주기
                d.push_back(arr1[i]);
            else cnt[arr1[i]]++; // 있으면 그냥 카운팅을 올려준다.
        }
        
        vector<int> result;
        sort(d.begin(), d.end()); // 오름차순으로 들어가야하기 때문에 소팅을 해주고 
        
        for (int i = 0 ; i < arr2.size() ; i++){
            for (int j = 0 ; j < cnt[arr2[i]] ; j++){ // 카운트에 저장된 갯수대로 값 벡터에 넣기
                result.push_back(arr2[i]);
            }
        }
        for (auto i : d){
            result.push_back(i); // 결과 벡터 제일 끝에 arr1에 만 존재하는 값들 넣어주기. 위에서 오름차순으로 정렬했으니까 그냥 넣어주기만 하면 된다.
        }
        return result;
    }
};