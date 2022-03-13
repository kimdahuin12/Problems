#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char str[256];
	int gatherCnt[255] = {0,};
	int numIdx = 0;

	while (true) {
		cin.getline(str, 256);
		if (str[0] == '#')break;
		for (int j = 0; j < strlen(str); j++)
		{
			char alpha = tolower(str[j]);
			if (alpha =='a'|| alpha == 'e'|| alpha == 'i'|| alpha == 'o'|| alpha == 'u') {
				gatherCnt[numIdx]++;
			}
		}
		numIdx++;
	}


	for (int i = 0; i < numIdx; i++)
	{
		cout << gatherCnt[i] << endl;
	}

	return 0;
}
