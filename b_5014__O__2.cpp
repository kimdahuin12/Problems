#include <iostream>
#include <queue>

using namespace std;

typedef struct myVertex {
public:
	int floor;
	int cnt;
}vertex;

int BFS(int start, int dest, int up, int down, int max)
{
	bool* found = new bool[max+1]{false,};
	queue<vertex> q;//확인할 값들
	//s층에서 +u, -d     값과 횟수(깊이)
	int temp[2] = { up, -down };
	/*int nowF = start, nowCnt = 0;
	int nextF = start, nextCnt = 0;*/
	vertex now = { start, 0 };
	vertex next = { 0, 0 };

	q.push(now);
	found[now.floor] = true;

	while (!q.empty()) {
		now = q.front(); q.pop();
		if (now.floor == dest) {
			return now.cnt;
		}

		//up, down 조사
		for (int i = 0; i < 2; i++) {
			next.floor = now.floor + temp[i];
			next.cnt = now.cnt + 1;
			if (next.floor > max || next.floor <= 0) continue;
			if (found[next.floor]) continue;
			q.push(next);
			found[next.floor] = true;
		}

	}

	return -1;
}

int main() {

	int f; //건물 층수
	int g; //스타트링크가 있는 곳의 층
	int s; //강호가 있는 층
	int u; //위로 u층 버튼
	int d; //아래로 d층 버튼

	cin >> f >> s >> g >> u >> d;

	int res = BFS(s, g, u, d, f);

	res != -1 ? cout << res : cout << "use the stairs";

	return 0;
}
