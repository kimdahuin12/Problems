#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct tagPos {
	int x;
	int y;
}Pos;

void EnQueue(Pos* q, Pos data, int* rear) {
	q[*rear] = data;
	(*rear)++;
}

Pos DeQueue(Pos* q, int* front) {
	return q[(*front)++];
}


int main() {

	int N, M;
	char** Matrix;
	char temp[101];

	scanf("%d %d", &N, &M);
	Matrix = (char**)malloc(sizeof(char*)*N);
	
	for (int i = 0; i < N; i++) {
		Matrix[i] = (char*)malloc(sizeof(char) * M+1);
		scanf("%s", temp);
		strcpy(Matrix[i], temp);
	}

	//BFS 후 역추적하며 횟수 셈

	Pos q_data[10001];
	int q_front = 0, q_rear = 0;//queue
	int nextX[] = { 0, 1, 0, -1 };
	int nextY[] = { 1, 0, -1, 0 };
	bool found[101][101] = {false,};
	Pos parent[101][101];
	Pos pos = {0, 0};
	Pos next;

	EnQueue(q_data, pos, &q_rear);
	found[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;

	//bfs
	while (q_front != q_rear) {
		pos = DeQueue(q_data, &q_front);

		//위, 오른, 아래, 왼 검사
		for (int i = 0; i < 4; i++) {
			next.x = pos.x+nextX[i];
			next.y = pos.y+nextY[i];

			if (next.x < 0 || next.y < 0 || next.x >= M || next.y >= N) { continue; }
			if (found[next.y][next.x]) { continue; }
			if (Matrix[next.y][next.x] == '0') { continue; }

			EnQueue(q_data, next, &q_rear);
			found[next.y][next.x] = true;
			parent[next.y][next.x] = pos;
		}
	}

	//역추적
	Pos tPos;
	int y = N - 1;
	int x = M - 1;
	int cnt = 0;
	while (parent[y][x].x != x || parent[y][x].y != y) {
		cnt++;
		tPos = parent[y][x];
		y = tPos.y;
		x = tPos.x;
	}
	if(parent[y][x].x == x && parent[y][x].y == y)
		cnt++;

	printf("%d", cnt);

	free(Matrix[0]);
	free(Matrix);

	return 0;
}
