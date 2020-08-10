#include <cstdio>
#include <utility>

using namespace std;

int map [51][51];
int result = 1;
int N, M;

void clean(pair<int, int> position){
    if(map [position.first][position.second] == 0){
        result += 1;
        map[position.first][position.second] = result;
    }
}

pair<int, int> move(pair<int, int> position, int dir){
    switch(dir) {
        case 0 :
            position = {position.first-1, position.second};
            break;
        case 1 :
            position = {position.first, position.second-1};
            break;
        case 2 :
            position = {position.first+1, position.second};
            break;
        case 3 :
            position = {position.first, position.second+1};
            break;
    }

    return position;
}

pair<int, int> rear(pair<int, int> position, int dir){
    switch(dir) {
        case 0 :
            position = {position.first+1, position.second};
            break;
        case 1 :
            position = {position.first, position.second+1};
            break;
        case 2 :
            position = {position.first-1, position.second};
            break;
        case 3 :
            position = {position.first, position.second-1};
            break;
    }

    return position;
}

bool isCleaned(pair<int, int> position, int dir){
    switch(dir) {
        case 0 :
            position = {position.first-1, position.second};
            break;
        case 1 :
            position = {position.first, position.second-1};
            break;
        case 2 :
            position = {position.first+1, position.second};
            break;
        case 3 :
            position = {position.first, position.second+1};
            break;
    }

    return map[position.first][position.second] > 1;
}

bool isWall(pair<int, int> position, int dir){
    switch(dir) {
        case 0 :
            position = {position.first-1, position.second};
            break;
        case 1 :
            position = {position.first, position.second-1};
            break;
        case 2 :
            position = {position.first+1, position.second};
            break;
        case 3 :
            position = {position.first, position.second+1};
            break;
    }

    return map[position.first][position.second] == 1;
}

bool isBound(pair<int, int> position, int dir){
    switch(dir) {
        case 0 :
            position = {position.first-1, position.second};
            break;
        case 1 :
            position = {position.first, position.second-1};
            break;
        case 2 :
            position = {position.first+1, position.second};
            break;
        case 3 :
            position = {position.first, position.second+1};
            break;
    }

    return position.first < 1 || position.second < 1 || position.first > N || position.second > M ;
}

int turnLeft (int dir){
    dir += 1;
    dir > 3 ? dir = 0 : dir;
    
    return dir;
}

int turnOpposite (int dir){
    if (dir < 2) dir += 2;
    else dir -= 2;
    
    return dir;
}

int main (){
    scanf("%d %d", &N, &M);

    int r, c, dir;
    scanf("%d %d %d", &r, &c, &dir);

    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < M ; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    pair<int, int> position = {r, c};

    clean(position);
    while(true){
        bool flag = false;
        for (int i = 0 ; i < 4 ; i ++){
            dir = turnLeft(dir);
            if(!isCleaned(position, dir) && !isWall(position, dir) && !isBound(position, dir)){
                position = move(position, dir);
                clean(position);
                flag = true;
                break;
            }
        }
        
        if (!flag){
            dir = turnOpposite(dir);
            if(isWall(position, dir) || isBound(position, dir)){
                break;
            }
            dir = turnOpposite(dir);
            position = rear(position, dir);
        }
        /*
        for (int i = 0 ; i < N ; i++){
            for (int j = 0 ; j < M ; j++){
                printf("%d\t", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
         */
    }

    printf("%d", result-1);
}
