/*zoj 1864
  题意：
  求自然数幂。
  限制：
  0 <= n <= 10^50; 1 <= k <= 100
  思路：
  k不大，而且答案不取模，直接搞
  (n+1)^(k+1) - n^(k+1) = C(k+1,1)*n^k + C(k+1,2)*n^(k-1) + ... + C(k+1,k)*n + 1;
  (n+1)^(k+1) - 1 = ( (n+1)^(k+1) - n^(k+1) ) + ( n^(k+1) - (n-1)^(k+1) ) + ... + ( 2^(k+1) - 1^(k+1) )
  =C(k+1,1)*(1^k+2^k+...+n^k) + C(k+1,2)*(1^(k-1)+2^(k-1)+...+n^(k-1)) + C(k+1,k)*(1+2+...+n) + n;
  令S(k,n)=1^k+2^k+...+n^k 得：
  (n+1)^(k+1) - 1 = C(k+1,1)*S(k,n) + C(k+1,2)*S(k-1,n) + ... + C(k+1,k)*S(1,n) + n;
  移项得：
  C(k+1,1)*S(k,n) = ...
  S(k,n) = 1/C(k+1,1) * ...
  能O(k^2)得出结果
  其实也可以用伯努利数来做。
  */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static final int N = 105;
	static final BigInteger _one = BigInteger.valueOf(-1);
	static BigInteger[][] C = new BigInteger[N][N];
	static BigInteger[] ans = new BigInteger[N];
	static BigInteger[] n1k1 = new BigInteger[N];

	static void predo() {
		for (int i = 0; i < N; ++i)
			C[i][0] = C[i][i] = BigInteger.ONE;
		for (int i = 2; i < N; ++i)
			for (int j = 1; j < i; ++j)
				C[i][j] = C[i - 1][j].add(C[i - 1][j - 1]);
	}

	static void init(BigInteger n, int k) {
		for (int i = 0; i <= k; ++i)
			ans[i] = _one;
		n1k1[0] = n.add(BigInteger.ONE);
		for (int i = 1; i <= k; ++i)
			n1k1[i] = n1k1[i - 1].multiply(n.add(BigInteger.ONE));
	}

	static BigInteger gao(BigInteger n, int k) {
		if (!ans[k].equals(_one))
			return ans[k];
		if (k == 1)
			ans[k] = n.add(BigInteger.ONE).multiply(n).divide(BigInteger.valueOf(2));
		else {
			ans[k] = n1k1[k].subtract(n.add(BigInteger.ONE));
			for (int i = 2; i <= k; ++i)
				ans[k] = ans[k].subtract(C[k + 1][i].multiply(gao(n, k - i + 1)));
			ans[k] = ans[k].divide(BigInteger.valueOf(k + 1));
		}
		return ans[k];
	}

	public static void main(String[] args) {
		predo();
		Scanner in = new Scanner(System.in);
		BigInteger n;
		int k;
		while (in.hasNext()) {
			n = in.nextBigInteger();
			k = in.nextInt();
			init(n, k);
			System.out.println(gao(n, k));
		}
	}
}
