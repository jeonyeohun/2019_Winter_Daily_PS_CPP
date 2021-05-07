#include <iostream>
#include <vector>

using namespace std;

void postOrder(vector<int>& pre, int start, int end) {
    if (start == end) return; // 노드가 없을 때 
    if (start == end - 1) {
        cout << pre[start] << "\n"; // 자녀노드 출력
        return;
    }

    int idx = start + 1;
    while (true) {
        if (idx >= end || pre[idx] > pre[start]) break;
        else idx++;
    }

    postOrder(pre, start + 1, idx); // 왼쪽 서브트리 
    postOrder(pre, idx, end); // 오른쪽 서브트리

    cout << pre[start] << "\n"; // 루트노드 출력
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int num;
    vector<int> pre;

    while (cin >> num) {
        pre.push_back(num);
    }

    postOrder(pre, 0, pre.size());
}