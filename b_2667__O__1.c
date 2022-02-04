#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int AllHouseResearch();
void BFS(int startY, int startX, int complexNum);

char Houses[25][25];
int ConnHouseCnt[25*25];
int mapWidth = 0;
int main() {

	//BFS
	//위 오른 아래 왼쪽

	//연결이 새로 시작될때마다 연결된 집 갯수를 얻는다.
	//(배열 공간에 연결된 집 갯수를 저장)

	//단지 수

	int ComplexNum = 0;

	scanf("%d", &mapWidth);

	for (int i = 0; i < mapWidth; i++) {
		scanf("%s", &Houses[i]);
	}
	
	ComplexNum = AllHouseResearch();

	for (int i = 0; i < ComplexNum-1; i++) {
		for (int j = i + 1; j < ComplexNum; j++) {
			if (ConnHouseCnt[j] < ConnHouseCnt[i]) {
				int temp = ConnHouseCnt[i];
				ConnHouseCnt[i] = ConnHouseCnt[j];
				ConnHouseCnt[j] = temp;
			}
		}
	}

	printf("%d\n", ComplexNum);
	for (int i = 0; i < ComplexNum; i++) {
		printf("%d\n", ConnHouseCnt[i]);
	}

	return 0;
}

bool visited[25][25] = { false, };
int AllHouseResearch() {
	int complexNum = 0;

	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (visited[i][j] == false && Houses[i][j] == '1') {
				BFS(i, j, complexNum);
				complexNum++;
			}
		}
	}

	return complexNum;
}

int nextY[] = { -1, 0, 1, 0 };
int nextX[] = { 0, 1, 0, -1 };
int secondY, secondX;
void BFS(int startY, int startX, int complexNum) {

	visited[startY][startX] = true;
	ConnHouseCnt[complexNum]++;

	for (int i = 0; i < 4; i++) {
		secondY = startY + nextY[i];
		secondX = startX + nextX[i];
		if (secondY < 0 || secondY >= mapWidth || secondX < 0 || secondX >= mapWidth) { continue; }
		if (visited[secondY][secondX]) { continue; }
		if (Houses[secondY][secondX] == '0') { continue; }
		
		BFS(secondY, secondX, complexNum);

	}

}
