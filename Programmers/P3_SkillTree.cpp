
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0 ; i < skill_trees.size() ; i++){
        vector<int> isPossible(skill.size(), 0);
        for (int j = 0 ; j < skill.size() ; j++){
            isPossible[j] = skill_trees[i].find(skill[j]);
        }

        bool ans = true;
        for (int j = 0 ; j < isPossible.size() ; j++){
            if (isPossible[j] == -1){
                for (int k = j+1 ; k < isPossible.size() ; k++){
                    if(isPossible[k] != -1) {
                        ans = false;
                        break;
                    }
                }
            }
            else if (j+1 < isPossible.size() && isPossible[j] > isPossible[j+1] && isPossible[j+1]!= -1) ans = false;
        }
        cout << skill_trees[i] << " " << ans << endl;
        if (ans) answer++;
    }
    return answer;
}