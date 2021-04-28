#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inOrder(vector<char>& binaryTree, int idx) {
    if (idx >= binaryTree.size() || binaryTree[idx] == '.') return;
    inOrder(binaryTree, idx * 2);
    cout << binaryTree[idx];
    inOrder(binaryTree, idx * 2 + 1);
}

void postOrder(vector<char>& binaryTree, int idx) {
    if (idx >= binaryTree.size() || binaryTree[idx] == '.') return;
    postOrder(binaryTree, idx * 2);
    postOrder(binaryTree, idx * 2 + 1);
    cout << binaryTree[idx];
}

void preOrder(vector<char>& binaryTree, int idx) {
    if (idx >= binaryTree.size() || binaryTree[idx] == '.') return;
    cout << binaryTree[idx];
    preOrder(binaryTree, idx * 2);
    preOrder(binaryTree, idx * 2 + 1);
}

int main() {
    int N; cin >> N;

    vector<char> binaryTree(70000000, '.');
    binaryTree[1] = 'A';
    for (int i = 1; i <= N; i++) {
        char root, left, right;

        cin >> root >> left >> right;
        int rootIdx = find(binaryTree.begin(), binaryTree.end(), root) - binaryTree.begin();
        binaryTree[rootIdx * 2] = left;
        binaryTree[rootIdx * 2 + 1] = right;
    }

    preOrder(binaryTree, 1);
    cout << "\n";
    inOrder(binaryTree, 1);
    cout << "\n";
    postOrder(binaryTree, 1);

}
