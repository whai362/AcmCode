import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

class Main {
	public static void main(String[] args) {
		BigDecimal n, ans, div, tmp, sum;
		int m;
		int T;
		Scanner in = new Scanner(System.in);
		T=in.nextInt();
		while(T-->0){
			n=in.nextBigDecimal();
			m=in.nextInt();
			//for (int i1 = 1; i1 <= 100000; ++i1) {
			//	for (int j = 1; j <= 5; ++j) {
			//		n=BigDecimal.valueOf(i1);
			//		m=j;
			ans = BigDecimal.ZERO;
			div = tmp = BigDecimal.ONE;
			sum = n.multiply(n.add(BigDecimal.ONE)).divide(
					BigDecimal.valueOf(2), 10, BigDecimal.ROUND_HALF_UP);
			for (int i = 0; i < m; ++i) {
				ans = ans.add(ans.multiply(n.subtract(BigDecimal.ONE)))
					.add(tmp.multiply(sum));
				tmp = tmp.multiply(n.subtract(BigDecimal.ONE));
				div = div.multiply(n);
			}
			ans = ans.divide(div, 10, BigDecimal.ROUND_HALF_UP);
			System.out.println(n+" "+m+" "+ans);
			//	}
		}
		}
	}
