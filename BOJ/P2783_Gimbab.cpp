#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    double gram, prce;
    int N;
    vector <double> price;

    scanf("%lf %lf", &prce, &gram);
    price.push_back(prce/gram);
    
    scanf("%d", &N);

    while(N--){
        scanf("%lf %lf", &prce, &gram);
        price.push_back(prce/gram);
    }
    
    sort(price.begin(), price.end());
    
    printf("%0.2f", price[0]*1000);
    return 0;
}

