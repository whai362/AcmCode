import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class Main {
	static long a_b_MOD_c(long a,long b,long mod){
		long ret = 1;
		a %= mod;
		while(b > 0){
			if((b & 1) > 0) ret = ret * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		return ret;
	}

	static double get_p(int x, int m) {
		double tmp = a_b_MOD_c(2, x, m - 1);
		tmp = tmp * Math.log(5 + 2 * Math.sqrt(6)) / Math.log(2);
		return tmp;
	}

	
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int x, m;
		x = in.nextInt();
		m = in.nextInt();
		BigDecimal v = BigDecimal.valueOf(5 + 2 * Math.sqrt(6));
		BigDecimal ans;
		
		double p = get_p(x, m);
		int p_int = (int)p;
		double p_flo = p - p_int;
		ans = BigDecimal.valueOf(2).pow(p_int);
		ans = ans.multiply(v);
		System.out.println(ans);
	}
}
