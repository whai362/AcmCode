/*hdu3723
  题意：
  求前n个默慈金数，mod(10^100)
  限制：
  0 <= n <= 10000
  思路：
  默慈金数
 */
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {
	static final int N = 10005;
	static final BigInteger MOD = BigInteger.valueOf(10).pow(100);
	static BigInteger[] ans = new BigInteger[N];

	static void predo() {
		ans[1] = BigInteger.ONE;
		ans[2] = BigInteger.valueOf(2);
		for (int i = 3; i < N; ++i) {
			BigInteger a = ans[i - 1].multiply(BigInteger.valueOf(2)
					.multiply(BigInteger.valueOf(i)).add(BigInteger.ONE));
			BigInteger b = ans[i - 2].multiply(BigInteger.valueOf(3).multiply(
					BigInteger.valueOf(i - 1)));
			ans[i] = a.add(b).divide(
					BigInteger.valueOf(i).add(BigInteger.valueOf(2)));
		}
	}

	public static void main(String[] args) {
		predo();
		Scanner in = new Scanner(System.in);
		int n;
		while (in.hasNext()) {
			n = in.nextInt();
			System.out.println(ans[n].mod(MOD));
		}
	}
}
