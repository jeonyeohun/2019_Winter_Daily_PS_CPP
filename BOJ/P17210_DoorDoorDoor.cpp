#include <iostream>

using namespace std;


void print_door(int cnt, int N, bool isTwo){
    if (cnt == N) return;
    cout << isTwo << endl;
    print_door(cnt+1, N, !isTwo);
}

int main (){
    int N; cin >> N;
    bool init; cin >> init;

    if (N > 6) {
        cout << "Love is open door";
        return 0;
    }

    print_door(1, N, !init);

    return 0;
}
