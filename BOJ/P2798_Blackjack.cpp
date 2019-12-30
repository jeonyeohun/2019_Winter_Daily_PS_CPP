#include <iostream>
#include <vector>

using namespace std;

int main (){
    int N, M;
    cin >> N >> M;
    vector<int> cards;

    while(N--){
        int card;
        cin >> card;
        cards.push_back(card);
    }

    int max = 0;

    for (int i = 0 ; i < cards.size()-2 ; i++){
        for (int j = i+1 ; j < cards.size()-1 ; j++){
            for (int k = j+1 ; k < cards.size() ; k++){
                int sum = cards[i]+cards[j]+cards[k];
                if (sum > max && sum <= M){
                    max = sum;
                }       
            }
        }
    }

    cout << max;
    return 0;
}