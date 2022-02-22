import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Pos{
	public Pos() {}
	public Pos(int width, int length, int height, int day) {
		this.width = width;
		this.length = length;
		this.height = height;
		this.day = day;
	}
	public void setPos(int width, int length, int height, int day) {
		this.width = width;
		this.length = length;
		this.height = height;
		this.day = day;
	}
	int width; //가로
	int length; //세로
	int height; //높이
	int day = -1;//지난날짜
}

public class Main {

	static int[][][] array = new int[100][100][100];
	
	public static void main(String[] args) {
		
		int N,M; //상자의 크기
		int H; //상자의 수
		Pos ripeTomato = new Pos();
		
		Scanner scan = new Scanner(System.in);
		
		Queue<Pos> q = new LinkedList<>();
		
		M = scan.nextInt(); //열
		N = scan.nextInt(); //행
		H = scan.nextInt(); //높이
		
		boolean found[][][] = new boolean[H][N][M]; //익은 토마토는 있었지만 익지 않았다면 -1
		int tempArray[][][] = new int[H][N][M];
		for (int boxCnt = 0; boxCnt < H; boxCnt++) {
			for(int x = 0; x < N; x++) {
				for(int y = 0; y < M; y++) {
					array[boxCnt][x][y] = scan.nextInt();
					tempArray[boxCnt][x][y] = array[boxCnt][x][y];
					if(array[boxCnt][x][y] ==1) {
						q.add(new Pos(y, x, boxCnt, 0)); //start
						found[boxCnt][x][y] = true;
					}
				}
			}
		}
		
		int res = -1;
		if(!q.isEmpty()) {
			//BFS

			Pos now = new Pos(), next= new Pos();
		
			int deltaH[] = {0, 0, 0, 0, -1, 1};
			int deltaL[] = {-1, 1, 0, 0, 0, 0};
			int deltaW[] = {0, 0, -1, 1, 0, 0};
			
			while(!q.isEmpty()) {
				now = q.poll();
				
				//마지막 now의 day가 일수일 것이다.
				for (int i = 0; i < deltaW.length; i++) {
					next = new Pos(now.width+ deltaW[i], now.length+ deltaL[i], now.height+ deltaH[i], now.day+1);
					if(next.height >= H || next.length >= N || next.width >= M||
							next.height < 0 || next.length < 0 || next.width < 0) {continue;}
					if(found[next.height][next.length][next.width]) {continue;}
					if(array[next.height][next.length][next.width]!= 0) {continue;}
					found[next.height][next.length][next.width] = true;
					tempArray[next.height][next.length][next.width] = 1;
					q.add(next);
				}
			}
			res = now.day;
			for (int boxCnt = 0; boxCnt < H; boxCnt++) {
				for(int x = 0; x < N; x++) {
					for(int y = 0; y < M; y++) {
						if(tempArray[boxCnt][x][y] == 0){
							res = -1;
							break;
						}
					}
				}
			}
		}
		System.out.println(res);
		
	}
}
