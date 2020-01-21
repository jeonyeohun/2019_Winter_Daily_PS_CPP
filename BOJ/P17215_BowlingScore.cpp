#include <iostream>
#include <vector>

using namespace std;

int main (){
    string score;
    vector<int> stk;
    cin >> score;

    for (int i = 0 ; i < score.size() ; i++){
        if (isdigit(score[i])) stk.push_back(score[i] - '0');
        if (score[i] == 'P'){
            if(score[i+1] == 'S'){

            }
            else if (isdigit(score[i+1])){
                
            }
        }

    }
}