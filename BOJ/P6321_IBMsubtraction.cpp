#include <cstdio>
#include <string.h>

using namespace std;

int main(){
    int t, i=1;
    scanf("%d", &t);
    
    while(t--){
        char name[50];
        scanf("%s", name);

        printf("String #%d\n", i++);
        for (int i =0 ; i < strlen(name) ; i++){
            if (name[i] == 'Z') name[i] = 64;
            printf("%c", name[i]+1);
        }
        printf("\n\n");
    }
    return 0;
}
