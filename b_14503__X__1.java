import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Pos{
	public Pos(int x, int y, int d) {
		this.x = x;
		this.y = y;
		this.d = d;
	}
	

	int x;
	int y;
	int d;
}

public class Main {
	
	public static void main(String[] args) {
		
		//b_14503
		
		int N, M; //세로, 가로
		int r, c, d; //x좌표, y좌표, 바라보는 방향
		//북 : 0, 동 : 1, 남 : 2, 서 : 3
		//빈칸 : 0, 벽 : 1
		//지도의 테두리는 벽
		
		Scanner scan = new Scanner(System.in);
		
		N = scan.nextInt();
		M = scan.nextInt();
		r = scan.nextInt();
		c = scan.nextInt();
		d = scan.nextInt();
		
		int space[][] = new int[N][M];
		
		for (int y = 0; y < space.length; y++) {
			for (int x = 0; x < space[0].length; x++) {
				space[y][x] = scan.nextInt();
			}
		}
		
		//r, c는 시작 좌표
		//d는 시작 방향
		
		//북 : 0, 동 : 1, 남 : 2, 서 : 3
		
		int cnt = 0;
		
		//북, 동, 남, 서 (시계방향)
		int deltaY[] = new int[] { -1, 0, 1, 0 };
		int deltaX[] = new int[] { 0, 1, 0, -1 };
		
		boolean[][] found = new boolean[N][M];
		Queue<Pos> q = new LinkedList<>();

		for (int y = 0; y < found.length; y++) {
			for (int x = 0; x < found[0].length; x++) {
				if(x == 0 || x == found[0].length-1 || y == 0 || y == found.length-1) {
					found[y][x] = true;
				}
			}
		}
		
		q.add(new Pos(r, c, d));
		
		while(!q.isEmpty()) {
			Pos now = q.poll();
			cnt++;
			
			/*1현재 위치를 청소한다.
			2현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색한다.
			왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
			왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
			네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
			네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.*/
			
			int i = 4;
			while(true) {
				for (; i > 0; i--) {
					Pos next = new Pos(now.x + deltaX[(now.d+3)%4], now.y + deltaY[(now.d+3)%4], (now.d+3)%4);
					if(space[next.y][next.x] == 1 || found[next.y][next.x]) {
						now.d = (now.d+3)%4;
						continue;
					}
					found[next.y][next.x] = true;
					q.add(next);
					break;
				}
				
				if(i==0) {
					Pos next = new Pos(now.x + -deltaX[now.d] , now.y + -deltaY[now.d], now.d);
					if(space[next.y][next.x] == 1) {
						q.clear();
						break;
					}else {
						i=4;
						now = next;
					}
				}else {
					break;
				}
			}
		}
		
		System.out.println(cnt);
		
	}

}
