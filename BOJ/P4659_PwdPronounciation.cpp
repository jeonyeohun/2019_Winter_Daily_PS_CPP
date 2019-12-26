#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main (){
    while(true){
        char pwd [20];
        int vowelcnt = 0;
        int cnsntcnt = 0;
        bool isConsec = false;
        bool isSame = false;
        bool isVowel = false;
        
        scanf("%s", pwd);
        if (!strcmp(pwd, "end"))break;
        
        for(int i = 0 ; i < strlen(pwd); i++){
            // 자음모음 판정 //
            if (pwd[i] == 'a' || pwd[i] == 'e' || pwd[i] == 'i' || pwd[i] == 'o' || pwd[i] == 'u') {
                cnsntcnt = 0;
                vowelcnt++;
                isVowel = true;
            }
            else{
                vowelcnt = 0;
                cnsntcnt++;
            }
            
            // 연속된 자음, 모음 판정 //
            if (vowelcnt >= 3 || cnsntcnt >= 3) isConsec = true;
            
            // e, o를 제외한 연속되는 알파벳 판정 //
            if (i < strlen(pwd)){
                if(pwd[i] == pwd[i+1] && (pwd[i] != 'e' && pwd[i] != 'o')) isSame = true;
            }
        }
        
        if (!isVowel || isConsec || isSame) printf("<%s> is not acceptable.\n", pwd);
        else printf("<%s> is acceptable.\n", pwd);
        
    }
    return 0;
}
