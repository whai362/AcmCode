/*hdu3723
  题意：
  求前n个默慈金数，mod(10^100)
  限制：
  0 <= n <= 10000
  思路：
  默慈金数
  1, 2, 4, 9, 21, 51, 127, 323, 835, 2188, 5798, 15511, 41835, 113634, 310572, 853467, 2356779, 6536382, 18199284, 50852019, 142547559, 400763223, 1129760415, 3192727797, 9043402501, 25669818476, 73007772802, 208023278209, 593742784829
  式子：
  M[n+1] = M[n] + ( M[0]*M[n-1] + M[1]*M[n-2] + ... + M[n-1]M[0] )
		 = ( (2n+3)*M[n] + 3n*M[n-1] ) / ( n+3 )
  默慈金数与卡特兰数：
  M[n]=for(int i=0;i<=floor(n/2);++i){
			+C(n,2i)Catalan(i)	
	   }
  应用：
  1.一个给定的数的默慈金数是在一个圆上的个点间，画出彼此不相交弦的全部方法的总数。比如为4时，方法数为9
  2.在一个网格上，若限定每步只能向右移动一格，可以右上，右下，向右，并禁止移动到y=0以下的地方，则以这种走法移动n步从(0,0)到(n,0)的可能形成的路径的总数
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
