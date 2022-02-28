
import java.util.Scanner;

public class Main {
	static int data[] = new int[50];
	
	public static int pibo(int n) {
		if(n == 0 ) {
			return 0;
		}else if(n <= 1) {
			return 1;
		}
		if(data[n]==0) {			
			data[n] = pibo(n-2)+pibo(n-1);
		}
		return data[n];
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt();
		
		System.out.println(pibo(N));
		
	}

}
