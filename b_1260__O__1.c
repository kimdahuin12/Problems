#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void DFS(int** matrix, int len, bool* visited, int now);
void BFS(int** matrix, int len, int start);

int main() {

	//정점 번호가 작은 것을 먼저 방문

	int N; //정점의 개수
	int M; //간선의 개수
	int V; //탐색 시작할 정점의 번호
	int t1, t2;

	scanf("%d%d%d", &N, &M, &V);
	int** Matrix = (int**)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++) {
		Matrix[i] = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++) {
			Matrix[i][j] = -1;
		}
	}

	//간선이 연결하는 두 정점의 번호
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &t1, &t2);
		Matrix[t1 - 1][t2 - 1] = t2;
		Matrix[t2 - 1][t1 - 1] = t1;
	}

	//정점 번호가 작은 것을 먼저 방문

	//DFS 수행 결과
	bool* visited = (bool*)malloc(sizeof(bool) * N);
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	DFS(Matrix, N, visited, V);

	printf("\n");
	//BFS 수행 결과
	BFS(Matrix, N, V);

	free(Matrix[0]);
	free(Matrix);
	return 0;
}

void DFS(int** matrix, int len, bool* visited, int now) {

	visited[now - 1] = true;
	printf("%d ", now);

	for (int next = 0; next < len; next++) {
		if (visited[next]) { continue; }
		if (matrix[now - 1][next] == -1) { continue; }
		DFS(matrix, len, visited, next+1);
	}
}

struct queue {
	int data[10000];
	int front;
	int rear;
};

void EnQueue(struct queue* q, int data) {
	q->data[q->rear] = data;
	q->rear++;
}

int DeQueue(struct queue* q) {
	return q->data[q->front++];
}


void BFS(int** matrix, int len, int start) {
	int now;

	bool* found = (bool*)malloc(sizeof(bool) * len);
	for (int i = 0; i < len; i++) { found[i] = false; }
	struct queue q;
	q.front = 0; q.rear = 0;

	EnQueue(&q, start - 1); //인덱스로 저장
	found[start - 1] = true;

	while(q.rear != q.front) {
		now = DeQueue(&q);
		printf("%d ", now+1);

		for (int next = 0; next < len; next++) {
			if (found[next]) { continue; }
			if (matrix[now][next] == -1) { continue; }
			EnQueue(&q, next);
			found[next] = true;
		}

	}

}
