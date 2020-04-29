#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> v;
    while(N--){
        int p;
        cin >> p;
		v.push_back(p);
    }

	sort(v.begin(), v.end());
	
	cout << v.front() * v.back();
}