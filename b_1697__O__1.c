#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int queue[10000000];
int q_front = 0, q_rear = 0;

int location[100001] = { -1, }; //-1은 방문 x, 배열의 각 칸에는 부모를 저장(start는 -2)

void ChkAndInsert(int now, int next)
{
	if (next < 0 || next >= 100001) { return; }
	if (location[next] == -1) {//방문 안 한 곳만
		location[next] = now;
		queue[q_rear++] = next;
	}
}

int main() {

	int N, K, count = 0;

	scanf("%d%d", &N, &K);

	if (N != K) {
		for (int i = 0; i <= 100000; i++){
			location[i] = -1;
		}

		int now = N;
		location[now] = -2; //시작점엔 -2
		queue[q_rear++] = N;

		while (q_rear >= q_front) {
			now = queue[q_front++];
			if (now == K) { break; }
			ChkAndInsert(now, now * 2);
			ChkAndInsert(now, now - 1);
			ChkAndInsert(now, now + 1);
		}

		//now부터 -2이 나올때까지 타고 올라감
		while (location[now] != -2) {
			count++;
			now = location[now];
		}

	}

	printf("%d\n", count);

	return 0;
}
