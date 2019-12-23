#include <iostream>
using namespace std;

int main (){
    int drm[8];
    int a = 0, d = 0;

    for (int i = 0 ; i < 8 ; i++){
        cin >> drm[i];
    }

    for (int i = 0 ; i < 7 ; i++){
        if (drm[i]-drm[i+1] == -1) a++;
        else if (drm[i]-drm[i+1] == 1) d++;
    }

    if (a == 7) cout << "ascending" << endl;
    else if (d == 7) cout << "descending" << endl;
    else cout << "mixed" << endl;

    return 0;
}