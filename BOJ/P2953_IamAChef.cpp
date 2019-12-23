#include <iostream>
#include <algorithm>

using namespace std;

int winner(int * scores);
int main(){
    int scores[5] = {0};

    for (int i = 0 ; i < 5 ; i ++){
        for (int j = 0 ; j < 4 ; j++){
            int score;
            cin >> score;
            scores[i] += score;
        }
      cout << "\nscores: " << scores[i] << endl;
    } 
    int w = winner(scores);
    cout << w+1 << " "<< scores[w] << endl;

    return 0;
}

int winner(int * scores){
    int winneridx = 0;
    int winnerscore =  scores[0];
    for (int i = 0 ; i < 5 ; i++){
        if (winnerscore < scores[i]){
            winnerscore = scores[i];
            winneridx = i;
        }
    }
    return winneridx;
}