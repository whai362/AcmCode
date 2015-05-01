/*题意：
  有一个正整数n，n的范围是[0,1000]，把它拆分成若干个数的和，n = x1 + x2 + ... + xk，使得(x1,x2,...,xk)的最小公倍数最大，求最大的最小公倍数S。
  思路：
  每一个正整数n都可以写成若干个素数的幂和1的和，其lcm最大。所以我们只需要考虑：
  n = p[1]^a1 + p[2]^a2 + ... + p[t]^at + 1 + ... + 1
  这种拆分就可以了。
 */
import java.math.BigInteger;
import java.util.*;

public class Main{
	static final int N = 2005;
	static boolean prime[] = new boolean[N];
	static int p[] = new int[N];
	static BigInteger dp[][] = new BigInteger[N][N];
	static BigInteger ans[] = new BigInteger[N];
	static int k;

	static void isprime(){
		k = 1;
		int i,j;
		Arrays.fill(prime,true);
		for(i=2;i<N;i++){
			if(prime[i]){
				p[k++] = i;
				for(j=i+i;j<N;j+=i){
					prime[j] = false;
				}
			}
		}
	}

	static BigInteger max(BigInteger a,BigInteger b){
		if(a.compareTo(b) == 1) return a;
		else return b;
	}

	static void Work(){
		for(int i=0;i<N;i++)
			for(int j=0;j<k;j++)
				dp[i][j] = BigInteger.ONE;
		for(int i=1;i<k;i++)
			dp[2][i] = BigInteger.valueOf(2);
		for(int i=3;i<N;i++){
			for(int j=1;j<k;j++){
				dp[i][j] = dp[i][j-1];
				int tmp = p[j];
				while(i >= tmp){
					dp[i][j] = max(dp[i][j],dp[i-tmp][j-1].multiply(BigInteger.valueOf(tmp)));
					tmp *= p[j];
				}
			}
		}
		ans[0] = ans[1] = BigInteger.ONE;
		ans[2] = BigInteger.valueOf(2);
		for(int i=3;i<N;i++){
			ans[i] = BigInteger.ZERO;
			for(int j=1;j<k;j++)
				ans[i] = max(ans[i],dp[i][j]);
		}
	}

	public static void main(String[] args){
		isprime();
		Work();
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			int n = cin.nextInt();
			System.out.println(ans[n]);
		}
	}
}
