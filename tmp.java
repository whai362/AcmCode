import java.math.*;
import java.util.*;

class Main {
	
	public static final int N = 105;
	public static final BigInteger FLAG = (BigInteger.ZERO).subtract(BigInteger.ONE);
	public static BigInteger[][] C = new BigInteger[N][N];
	public static BigInteger[] ans = new BigInteger[N];
	
	public static void Init(){
		for(int i=0; i<N; i++){
			C[i][0] = C[i][i] = BigInteger.ONE;
			if(i == 0) continue;
			for(int j=1; j<i; j++)
				C[i][j] = C[i-1][j].add(C[i-1][j-1]);
		}
	}
	
	public static BigInteger Solve(BigInteger n, int k){
		if(ans[k].compareTo(FLAG) != 0){
			return ans[k];
		}
		if(k == 1){
			ans[k] = ((n.add(BigInteger.ONE)).multiply(n)).divide(BigInteger.valueOf(2));
			return ans[k];
		}
		BigInteger tmp = BigInteger.ONE;
		for(int i=0; i<k+1; i++){
			tmp = tmp.multiply(n.add(BigInteger.ONE));
		}
		tmp = tmp.subtract(n.add(BigInteger.ONE));
		BigInteger sum = BigInteger.ZERO;
		for(int i=1; i<k; i++){
			BigInteger t = C[k+1][i+1].multiply(Solve(n, k-i));
			sum = sum.add(t);
		}
		ans[k] = (tmp.subtract(sum)).divide(BigInteger.valueOf(k+1));
		return ans[k];
	}
	
	public static void main(String[] args){
		Init();
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			BigInteger n = cin.nextBigInteger();
			int k = cin.nextInt();
			for(int i=0; i<N; i++){
				ans[i] = FLAG;
			}
			System.out.println(Solve(n, k));
		}
	}
}

