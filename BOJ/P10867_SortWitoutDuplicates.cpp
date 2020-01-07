#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    set<int> s;
    cin >> N;

    while(N--){
        int n;
        cin >> n;
        s.insert(n);
    }

    for(auto i : s){
        cout << i << " ";
    }
    return 0;
}