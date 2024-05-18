import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.FileInputStream;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)
		{
		
			int N = sc.nextInt();
			int M = sc.nextInt();
			
			int[][] map = new int[N][N];
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
//					System.out.print(map[i][j]+" ");
				}
//				System.out.println();
			}
			
			int maxFly = 0;
			
			for(int i = 0; i <= N-M; i++) {
				for(int j = 0; j <= N-M; j++) {
					maxFly = Math.max(maxFly, slap(map, M, i, j));
				}
			}
			
			System.out.println("#"+test_case+" "+maxFly);

		}
	}
	
	public static Integer slap(int[][] map, int m, int r, int c) {
		int sum = 0;
		
		for(int i = r; i < r+m; i++) {
			for(int j = c; j < c+m; j++) {
				sum += map[i][j];
			}
		}
		
		return sum;
	}
}