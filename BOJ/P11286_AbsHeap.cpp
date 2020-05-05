#include <cstdlib>
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    while(N--){
        int op;
        cin >> op;
        if (op == 0){
            if(pq.empty()) cout << 0 << endl;
            else {
                cout << pq.top().second << endl;
                pq.pop();
            }
        }
        else{
            pq.push(make_pair(abs(op), op));
        }
    }
    
}