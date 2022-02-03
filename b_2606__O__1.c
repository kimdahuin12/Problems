#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void Virus(int computerNum, int start);

int virusNum = 0;
bool Computers[101][101] = { false, };
int main() {
	int Number, PairNum;
	int Num1, Num2;
	scanf("%d%d", &Number, &PairNum);

	for (int i = 0; i < PairNum; i++) {
		scanf("%d%d", &Num1, &Num2);
		Computers[Num1][Num2] = true;
		Computers[Num2][Num1] = true;
	}
	
	Virus(Number, 1);

	printf("%d", virusNum);

	return 0;
}

bool visited[101] = { false, };
void Virus(int computerNum, int start) {

	visited[start] = true;

	for (int next = 1; next <= computerNum; next++) {
		if (visited[next]) { continue; }
		if (Computers[start][next] == false) { continue; }

		virusNum++;
		Virus(computerNum, next);
	}

}
