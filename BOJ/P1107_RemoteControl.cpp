#include <iostream>
#include <vector>

using namespace std;

void repeatedPerm(vector<int> set, int setSize, int n, int r);
int main(){
    int M, bbutton;
    string N;
    vector<int> bb = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cin >> N >> M;

    while(M--){
        cin >> bbutton;
        bb.erase(find(bb.begin(), bb.end(), bbutton));
    }
    
    string result;
    int flag = 0;
    for (int i = 0 ; i < N.size() ; i++){
        if (flag == 0){
            if (find(bb.begin(), bb.end(), N[i]-'0')!= bb.end()){
                result.push_back(N[i]);
                flag = 0;
            }
            else {
                int min = 10;                    
                char minN;
                for (int i = 0 ; i < bb.size() ; i++){
                    int diff = abs((N[i]-'0') - bb[i]);
                    if (diff < min) {
                        min = diff;
                        minN = N[i];
                    }
                }
                if (minN > N[i]) flag = 1;
                else flag = -1;
            }
         }
        else if (flag == 1){
            int max 
        }
    }
    
}
