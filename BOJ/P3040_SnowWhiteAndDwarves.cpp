#include <cstdio>
#include <vector>

using namespace std;

int main(){
    vector<int> dwarves;
    
    // 입력 받기 //
    for (int i = 0 ; i < 9 ; i++){
        int dwarf;
        scanf("%d", &dwarf);
        dwarves.push_back(dwarf);
    }
    
    int sum = 0;
    vector <int> result;
    for (int i = 0 ; i < 8 ; i++){
        for (int j = i+1 ; j < 9 ; j++){
            result.assign(dwarves.begin(), dwarves.end()); // 새로운 벡터 만들고 난쟁이 목록을 복사
            sum = 0; result[i] = 0 ; result[j] = 0; // i 와 j 번째 난쟁이를 0으로 만든다. 어차피 입력은 1이상으로 들어오기 때문에 상관없음
            for(int dw : result){
                sum += dw; // 난쟁이 더하기
            }
            if (sum == 100){ // 100이 되면 0으로 만든 난쟁이들만 없애고 출력해준다.
                for(int dw : result){
                    if (dw == 0) continue;
                    printf("%d\n", dw);
                }
                return 0;   
            }
        }   
    }

    return 0;
}