import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.math.BigInteger;

import javax.swing.JCheckBox;

class Main {
	static BigInteger[] jc=new BigInteger[3005],
	b=new BigInteger[3005];
	static int[] a=new int[3005];
	public static void main(String[] args) {
		double pre=System.currentTimeMillis();
		
		//Scanner in=new Scanner(System.in);
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		
		/*jc[0]=BigInteger.ONE;
		for(int i=1;i<=3000;++i){
			jc[i]=jc[i-1].multiply(BigInteger.valueOf(i));
		}*/
		int n,T;
		T=in.nextInt();
		for(int t=0;t<T;++t){
			n=in.nextInt();
			for(int i=0;i<n;++i){
				a[i]=in.nextInt();
			}
			b[0]=b[n-1]=BigInteger.ONE;
			for(int i=1;i<=(n-1)/2;++i){
				b[i]=b[n-1-i]=b[i-1].multiply(BigInteger.valueOf(n-i)).divide(BigInteger.valueOf(i));
			}
			/*for(int i=0;i<n;++i){
				out.print(b[i]);
			}
			out.println("");*/
			BigInteger ans=BigInteger.ZERO,tmp,fh=BigInteger.ONE;
			for(int i=n-1;i>=0;--i){
				tmp=BigInteger.valueOf(a[i]).multiply(b[i]).multiply(fh);
				ans=ans.add(tmp);
				fh=fh.multiply(BigInteger.valueOf(-1));
			}
			out.println(ans);
		}
		double post=System.currentTimeMillis();
		out.println(post-pre);
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

