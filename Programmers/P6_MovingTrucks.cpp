#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    deque<int> bridge(bridge_length);

    int totalWeight = 0;
    int idx = 0;

    while (true) {
        answer++;
        totalWeight -= bridge.back();
        bridge.pop_back();
        if (idx < truck_weights.size() && totalWeight + truck_weights[idx] <= weight) {
            totalWeight += truck_weights[idx];
            bridge.push_front(truck_weights[idx++]);
        }
        else {
            bridge.push_front(0);
        }

        if (totalWeight == 0) break;
    }

    return answer;
}