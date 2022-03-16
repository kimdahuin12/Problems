#include <iostream>

using namespace std;

int NArrT[100][100] = { 0, }; //비에 잠긴 곳을 1, 아니면 0
int N;
int cnt = 0;

struct myPos {
	int x;
	int y;
}typedef Pos;

//위, 아래, 오른, 왼
//
int deltaX[] = { 0, -1, 0, 1 };
int deltaY[] = { -1, 0, 1, 0 };
void DFS(Pos now)
{
	NArrT[now.y][now.x] = 1;

	for (int i = 0; i < 4; i++)
	{
		Pos next = { now.x + deltaX[i], now.y + deltaY[i] };
		if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= N)continue;
		if (NArrT[next.y][next.x] == 1)continue; //비에 잠긴곳이면 X
		DFS(next);
	}

}

void AllDFS()
{
	cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (NArrT[i][j]==0)
			{
				//비에 잠기지 않은 곳이면.
				cnt++;
				DFS({ j, i });
			}
		}
	}
}

int main() {
	int cntArr[101]; //각 높이에 따른 안전영역 개수 저장
	int NArr[100][100];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> NArr[i][j];
		}
	}

	//0 ~ 다 잠길때까지

	int maxCnt = 0;
	for (int cntIdx = 0; cntIdx < 101; cntIdx++) {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (cntIdx >= NArr[i][j])
				{
					NArrT[i][j] = 1;
				}
				else
				{
					NArrT[i][j] = 0;
				}
			}
		}

		//dfs 이용
		AllDFS();
		if (maxCnt < cnt)maxCnt = cnt;
		if (cnt == 0)break; //모두 잠겼다면 이제 X -- 안전영역이 하나도 없음
	}

	cout << maxCnt;

	return 0;
}
