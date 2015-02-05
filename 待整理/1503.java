import java.util.*;
import java.math.*;
class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		BigInteger a,sum=BigInteger.ZERO;
		while(in.hasNext()){
			a=in.nextBigInteger();
			if(a.compareTo(BigInteger.ZERO)==0) break;
			sum=sum.add(a);
		}
		System.out.println(sum);
	}
}
