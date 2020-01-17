#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, bool>> parking; // 주차된 차량과 현재 비어있는 자리인지 여부를 저장 
vector<int> r_i; // i번째 주차 공간의 무게 당 요금
vector<int> w_i; // i번째 차량의 무게

bool push_car (int carnum){ // 제일 낮은 자리에 차량 넣기 성공시 true, 자리가 꽉차서 실패시 false
    for(int j = 0 ; j < parking.size() ; j++){
        if (parking[j].second == false){
            parking[j].second = true;
            parking[j].first  = carnum;
            return true;
        }
    }
    return false;
}

int pop_car(int carnum){ // 입력된 숫자의 차량 빼기, 그리고 주차 요금 계산 
    for (int j = 0 ; j < parking.size() ; j++){
        if(parking[j].first == carnum){
            parking[j].second = false;
            return r_i[j] * w_i[carnum-1];
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        vector<int> queue; // 차량 대기열
        int sum = 0; // 총 요금

        int M, N;
        cin >> N >> M;

        for (int i = 0 ; i < N ; i++){
            int r; cin >> r;
            r_i.push_back(r);
        }
        for (int i = 0 ; i < M ; i++){
            int r; cin >> r;
            w_i.push_back(r);
        }

        parking.resize(r_i.size());

        for (int i = 0 ; i < 2*M ; i++){
            int turn; cin >> turn;
            if (turn < 0){
                sum += pop_car(turn*-1); // 차량 빼고 요금 계산
                if (!queue.empty()) {
                    push_car(queue.front()); // 대기열에 차가 있으면 넣어준다.
                    queue.erase(queue.begin()); // 대길열에 있는 차가 들어갔으므로 맨 앞에 있는 차량 정보 삭제
                }
            }
            else { // 차량 넣기
                bool isGood = push_car(turn);
                if (!isGood) queue.push_back(turn); // 차량 넣기 실패시 주차장이 꽉찬거니까 대기열로 보냄
            }
        }

        cout << "#" << test_case << " " << sum << "\n";
        parking.clear();
        r_i.clear();
        w_i.clear();
    }
    return 0;
}
