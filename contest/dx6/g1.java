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
	static BigInteger[][] yh=new BigInteger[3005][3005];
	static int[] a=new int[3005];
	public static void main(String[] args) {
		double pre=System.currentTimeMillis();
		
		//Scanner in=new Scanner(System.in);
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		
		for(int i=0;i<=3000;++i){
			yh[i][0]=BigInteger.ONE;
		}
		for(int i=1;i<=3000;++i){
			yh[i][i]=BigInteger.ONE;
		}
		for(int i=1;i<=3000;++i){
			for(int j=1;j<i;++j){
				yh[i][j]=yh[i-1][j].add(yh[i-1][j-1]);
			}
		}
		/*int n,T;
		T=in.nextInt();
		for(int t=0;t<T;++t){
			n=in.nextInt();
			for(int i=0;i<n;++i){
				a[i]=in.nextInt();
			}
			BigInteger ans=BigInteger.ZERO,tmp,fh=BigInteger.ONE;
			for(int i=n-1;i>=0;--i){
				tmp=BigInteger.valueOf(a[i]).multiply(jc[n-1].divide(jc[i].multiply(jc[n-1-i]))).multiply(fh);
				ans=ans.add(tmp);
				fh=fh.multiply(BigInteger.valueOf(-1));
			}
			out.println(ans);
		}*/
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
