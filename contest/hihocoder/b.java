import java.math.*;
import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		BigInteger ans,t1,t2,t3,n,n1,n2,n3,n6,M;
		int t;
		n1=BigInteger.valueOf(1);
		n2=BigInteger.valueOf(2);
		n3=BigInteger.valueOf(3);
		n6=BigInteger.valueOf(6);
		M=BigInteger.valueOf(1000000007);
		int i;
		t=in.nextInt();
		for(i=1;i<=t;++i){
		n=in.nextBigInteger();
		t1=n.add(n1).multiply(n).divide(n2);
		t2=n.multiply(n.add(n1)).multiply(n.multiply(n2).add(n1)).divide(n6);
		t3=t1.multiply(t1);
		ans=t1.multiply(t1).multiply(t1).subtract(t2.multiply(t1).multiply(n3)).add(n3.multiply(t3)).mod(M);
		System.out.println("Case "+i+": "+ans);
		}
	}
}

