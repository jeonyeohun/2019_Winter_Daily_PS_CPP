#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<bool> isDone(routes.size(), false);

    sort(routes.begin(), routes.end(), cmp);

    for (int i = 0; i < routes.size(); i++) {
        if (isDone[i]) continue;
        for (int j = 0; j < routes.size(); j++) {
            if (routes[j][0] <= routes[i][1]) {
                isDone[j] = true;
            }
        }
        answer++;
    }

    return answer;
}

int main() {
    cout << solution({ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }); //2
    cout << endl;
    cout << solution({ {-2, -1}, {1, 2}, {-3, 0} });//2
    cout << endl;
    cout << solution({ {0, 0}, });//1
    cout << endl;
    cout << solution({ {0, 1}, {0, 1}, {1, 2} });//1
    cout << endl;
    cout << solution({ {0, 1}, {2, 3}, {4, 5}, {6, 7} });//4
    cout << endl;
    cout << solution({ {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
    cout << endl;
    cout << solution({ {-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
    cout << endl;
    cout << solution({ {2,2},{0,1},{-10,9} });//2
    cout << endl;
    cout << solution({ {-7, 0}, {-6, -4}, {-5, -3}, {-3, -1}, {-1, 4}, {1, 2}, {3, 4} });//4
    cout << endl;
    cout << solution({ {-5, -3}, {-4, 0}, {-4, -2}, {-1, 2}, {0, 3}, {1, 5}, {2, 4} });//2
    cout << endl;
    cout << solution({ {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15} });//8
    cout << endl;
    cout << solution({ {0, 12}, {1, 12}, {2, 12}, {3, 12}, {5, 6}, {6, 12}, {10, 12} });//2
    cout << endl;
    cout << solution({ {-191, -107}, { -184,-151 }, { -150,-102 }, { -171,-124 }, { -120,-114 } }); // 2
    cout << endl;
}