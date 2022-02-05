#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int queue[100000];
int q_front = 0, q_rear = 0;

void Enqueue(int data) {
	queue[q_rear++] = data;
}

int Dequeue() {
	return queue[q_front++];
}

int main() {

	//그래프로 모든 사람들의 관계를 표현
	//BFS 미로찾기 알고리즘 사용
	//역추적할 때 갯수를 셈

	int n, m; 
	int startNum, destNum;
	int temp1, temp2;
	bool people[101][101] = { false, };

	scanf("%d", &n); //전체 사람의 수
	scanf("%d%d", &startNum, &destNum); //촌수 계산할 서로 다른 두 사람의 번호
	scanf("%d", &m); //부모 자식들 관계 개수

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &temp1, &temp2);
		people[temp1][temp2] = true;
		people[temp2][temp1] = true;
	}

	int parent[101] = { -1 };
	int start = startNum;
	bool found[101] = { false };

	Enqueue(start);
	parent[start] = start;
	found[start] = true;

	while (q_rear >= q_front) {
		start = Dequeue();

		for (int next = 1; next <= n; next++) {
			if (found[next]) { continue; }
			if (people[start][next] == false) { continue; }

			Enqueue(next);
			parent[next] = start;
			found[next] = true;

		}
	}
	int cnt = 0;
	//도착지점에서 출발지점으로 역추적
	while(startNum != destNum) {
		destNum = parent[destNum];
		cnt++;
	}
	printf("%d", cnt);

	return 0;
}
