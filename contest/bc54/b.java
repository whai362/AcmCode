import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class Main {
	
	BigInteger[] a = new BigInteger[105];
	
	boolean ok(int n) {
		if(n <= 1) return true;
		int flag = 1, has_0 = 0;
		for(int i = 0; i < n; ++i) {
			if(!a[i].equals(BigInteger.ZERO)){
				flag = 0;
				break;
			} else {
				has_0 = 1;
			}
		}
		if(flag == 1) {
			return true;
		} else if(has_0 == 1) {
			return false;
		}
		flag = 1;
		for(int i = 1; i < n - 1; ++i) {
			if(!a[i-1].multiply(a[i + 1]).equals(a[i].multiply(a[i]))) {
				flag = 0;
				break;
			}
		}
		if(flag == 1) {
			return true;
		} else {
			return false;
		}
	}
	
	void gao(Scanner in, PrintWriter out) {
		int T;
		T = in.nextInt();
		while(T-->0) {
			int n;
			n = in.nextInt();
			for(int i = 0; i < n; ++i) {
				a[i] = in.nextBigInteger();
			}
			if(ok(n)) {
				out.println("Yes");
			} else {
				out.println("No");
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		new Main().gao(in, out);
		out.flush();
		in.close();
		out.close();
	}
}
