#include <iostream>

using namespace std;
int main() {

	int n, k;
	int s[100000];
	int line[1000] = {0,};
	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++){
		cin >> s[i];//출발점에서 회사까지의 거리/가장 작은 것에서 가장 큰 것 까지 순서대로 나타난다.
	}

	//옆에 있는 곳의 거리를 저장한다.
	//거리 중 가장 작은 것들 k개를 뽑는다.
	int lineIdx = 0;
	for (int i = 0; i < n-1; i+=2) {
		line[lineIdx++] = s[i + 1] - s[i];
	}
	if (n % 2 == 1) {
		//홀수
		line[lineIdx] = s[n-1] - s[n-2];
	}

	for (int i = 0; i < lineIdx-1; i++) {
		for (int j = i+1; j < lineIdx; j++) {
			if (line[i] > line[j]) {
				int temp = line[i];
				line[i] = line[j];
				line[j] = temp;
			}
		}
	}
	int res = 0;
	if (k > lineIdx) k = lineIdx;
	for (int i = 0; i < k; i++) {
		res += line[i];
	}
	cout << res;
	return 0;
}
