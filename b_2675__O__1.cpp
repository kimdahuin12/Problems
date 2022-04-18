#include <iostream>
using namespace std;
int main() {

    int T;
    int R[1000];
    string S[1000];

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> R[i];
        cin >> S[i];
    }

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < S[i].length(); j++) {
            for (int a = 0; a < R[i]; a++) {
                cout << S[i][j];
            }
        }
        cout << endl;
    }
    
    return 0;
}
