#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    map<string, string> pokemonName;
    map<string, string> pokemonNum;

    int N, M; cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string name; cin >> name;
        pokemonName.insert({ name, to_string(i) });
        pokemonNum.insert({ to_string(i), name });
    }

    for (int i = 0; i < M; i++) {
        string in; cin >> in;
        cout << pokemonName[in];
        cout << pokemonNum[in] << "\n";
    }
}