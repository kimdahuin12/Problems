#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int len = 10;
	string colorName[] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
	string colorValue[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	unsigned int colorTimes[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
	int idx[3] = {0,};
	string tempStr;

	unsigned long long res = 0;
	
	for (int i = 0; i < 3; i++)
	{
		cin >> tempStr;
		for (int j = 0; j < len; j++)
		{
			if (tempStr.compare(colorName[j])==0)
			{
				idx[i] = j;
				break;
			}
		}
	}
	
	tempStr = colorValue[idx[0]];
	tempStr.append(colorValue[idx[1]]);
	res = stoi(tempStr);
	res *= colorTimes[idx[2]];

	cout << res;
	
	return 0;
}
