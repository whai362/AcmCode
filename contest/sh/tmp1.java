import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
class Main {
	public static void main(String[] args) {
		//double pre=System.currentTimeMillis();
		Scanner in=new Scanner(System.in);
		//InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		//InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		
		int T;
		BigInteger n,
		n1=BigInteger.valueOf(1),
		n7=BigInteger.valueOf(7),
		n8=BigInteger.valueOf(8);
		T=in.nextInt();
		for(int t=1;t<=T;++t){
			n=in.nextBigInteger();
			out.println("Case #"+t+": "+n.multiply(n).multiply(n8).subtract(n.multiply(n7)).add(n1));
		}
		//double post=System.currentTimeMillis();
		//out.println(post-pre);
		out.close();
	}
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}
