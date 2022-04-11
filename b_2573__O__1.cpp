#include <iostream>
#include <queue>

using namespace std;

typedef struct myVertex {
	int x;
	int y;
}vertex;

bool visited[300][300];
int arr[300][300];
int N, M; //N은 행, M은 열
int lump = 0; //덩어리
int deltaX[] = {1, 0, -1, 0};
int deltaY[] = {0, -1, 0, 1};
int year = -1;
void DFS(vertex start) {
	visited[start.y][start.x] = true;

	//빙산 깎기
	for (int i = 0; i < 4; i++) {
		vertex chk = { start.x + deltaX[i], start.y + deltaY[i] };
		if (arr[chk.y][chk.x] == 0) {
			arr[start.y][start.x]--;
		}
		if (arr[start.y][start.x] <= 0) {
			arr[start.y][start.x] = -1;
			break;
		}
	}

	//오른, 아래, 왼, 위순으로 확인하여 next 정점 찾기
	for (int i = 0; i < 4; i++) {
		vertex next = {start.x+deltaX[i], start.y + deltaY[i] };
		if (next.x < 0 || next.y < 0 || next.x >= M || next.y >= N)continue;
		if (visited[next.y][next.x])continue;
		if (arr[next.y][next.x] == 0|| arr[next.y][next.x] == -1)continue;
		DFS(next);
	}
}

void allSearch() {
	lump = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
			if (arr[i][j] == -1) arr[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != 0 && !visited[i][j]) {//-1은 빙산이었던 공간
				lump++;
				DFS({ j, i });
			}
		}
	}
	//lump가 0이면 덩어리가 하나도 없다.
}

int main() {

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	lump = 1; //처음에 한 덩어리
	while (lump < 2) { 
		allSearch();
		year++;
		if (lump == 0) {
			year = 0;
			break;
		}
	}
	cout << year;
	return 0;
}

