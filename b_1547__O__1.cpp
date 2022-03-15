#include <iostream>
#include <cstring>

using namespace std;

int main() {

	int len;
	int cup[50][2];
	int loc = 1;//처음 공의 위치 : 1

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 2; j++) {
			cin >> cup[i][j];
		}
		for (int j = 0; j < 2; j++) {
			if (cup[i][j] == loc) {
				loc = cup[i][(j + 1) % 2];
				break;
			}
		}
	}

	cout << loc;

	return 0;
}
