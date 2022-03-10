import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static ArrayList<Integer> list = new ArrayList<>();
	public static int X;
	public static int res = 0;
	
	public static void cut()
	{
		int minIdx = list.size()-1;
		
		int sum = 0;
		for (Integer integer : list) {
			sum+=integer;
		}
		if(sum <= X) {
			res = list.size();
			return;
		}
		int min =list.get(minIdx)/2;
		list.set(minIdx, min);
		list.add(min);
		
		sum = 0;
		for (int i = 0; i < list.size()-1; i++) { //절반 중 하나를 버리고의 합
			sum+=list.get(i);
		}
		
		if(sum>=X) {
			list.remove(minIdx+1);
		}
		cut();
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		list.add(64);
		X = scan.nextInt();
		cut();
		System.out.println(res);
		
		
		//b_1094
		
	}

}
