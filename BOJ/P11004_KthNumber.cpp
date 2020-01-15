#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int A, N;
    cin >> A >> N;
    vector<int> v;
    while(A--){
        int n;
        cin >> n;
        v.push_back(n);
    }
    nth_element(v.begin(), v.begin()+N-1, v.end());

    cout << v[N-1];
}
