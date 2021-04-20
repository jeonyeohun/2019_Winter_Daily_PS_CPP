#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    for (int col = 3; col <= yellow + 2; col++) {
        for (int row = 3; row <= col; row++) {
            if ((col - 2) * (row - 2) == yellow
                && col * row == brown + yellow) {
                return { col, row };
            }
        }
    }
}