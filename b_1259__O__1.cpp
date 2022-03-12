#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char num[100000];
	bool palidrome[100000];
	int numIdx = 0;

	while (true) {
		cin >> num;
		if (num[0] == '0')break;
		palidrome[numIdx] = true;
		for (int j = 0; j < strlen(num) / 2; j++)
		{
			if (num[j] != num[strlen(num) - 1 - j]) {
				palidrome[numIdx] = false;
			}
		}
		numIdx++;
	}


	for (int i = 0; i < numIdx; i++)
	{
		cout << (palidrome[i]?"yes":"no") << endl;
	}

	return 0;
}
