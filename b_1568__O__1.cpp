#include <iostream>
#include <sstream>

using namespace std;

int main() {
	
	//1~...
	int N;
	int res = 0;

	cin >> N;

	int num = 1;

	while (N != 0) {
		if (N >= num) {
			N -= num;
			res++;
			num++;
		}
		else {
			num = 1;
		}
	}

	cout << res;

	return 0;
}
