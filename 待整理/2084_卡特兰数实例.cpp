import java.util.*;
import java.math.*;
class Main{
	static final int N=105;
	static BigInteger[] ans=new BigInteger[N];
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		ans[0]=BigInteger.ZERO;
		ans[1]=BigInteger.ONE;
		for(int i=2;i<105;++i)
			ans[i]=ans[i-1].multiply(BigInteger.valueOf(4*i-2)).divide(BigInteger.valueOf(i+1));
		int n;
		while(in.hasNext()){
			n=in.nextInt();
			if(n==-1) break;
			System.out.println(ans[n]);
		}
	}
}
