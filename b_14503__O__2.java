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
		int r, c, d; //y좌표, x좌표, 바라보는 방향
		
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
		
		found[r][c] = true;
		q.add(new Pos(c, r, d));
		
		while(!q.isEmpty()) {
			Pos now = q.poll();
			cnt++;
			
			int i = 4;
			while(true) {
				for (; i > 0; i--) {
					Pos next = new Pos(now.x + deltaX[(now.d+3)%4], now.y + deltaY[(now.d+3)%4], (now.d+3)%4);
					if(space[next.y][next.x] == 1||found[next.y][next.x]) {
						now.d = (now.d+3)%4;
						continue;
					}
					found[next.y][next.x] = true;
					q.add(next);
					break;
				}

				if(i==0) {
					Pos next = new Pos(now.x-deltaX[now.d] , now.y-deltaY[now.d], now.d);
					if(space[next.y][next.x] == 1) {
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
