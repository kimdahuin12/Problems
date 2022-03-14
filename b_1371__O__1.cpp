#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
	
	char c;
	int alpha[26] = { 0, }; //a : 97
	int max = 0;
	while (true) {
		cin >> c;
		if (cin.eof() == true) {
			break;
		}
		alpha[c-97]++;
		if (max < alpha[c - 97]) {
			max = alpha[c - 97];
		}
	}

	for (int i = 0; i < 26; i++){
		if (alpha[i] == max) {
			cout << char(i + 97);
		}
	}

	return 0;
}
