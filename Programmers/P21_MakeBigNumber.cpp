#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int eraseCount = 0;
    int initialSize = number.size();
    while (eraseCount != k) {
        for (int i = 0; i < number.size() - 1; i++) {
            if (number[i] < number[i + 1]) {
                number.erase(number.begin() + i);
                break;
            }
        }
        eraseCount++;
    }

    if (number.size() != initialSize - k) {
        number.pop_back();
    }

    return number;
}