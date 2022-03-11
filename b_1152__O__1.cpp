#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char str[1000001];

	cin.getline(str, 1000001);

	int len = strlen(str);
	int cnt = 0;
	bool nextWord = false;

	for (int i = 0; i < len; i++)
	{
		if (!nextWord) {
			if (str[i] != ' ') {
				nextWord = true;
				cnt++;
			}
		}
		else {
			if (str[i] == ' ') {
				nextWord = false;
			}
		}
	}

	cout << cnt;
	return 0;
}
