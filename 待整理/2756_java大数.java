import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		String s;
		BigInteger a,b,n;
		s=in.next();
		s=s.replaceAll("\\+","");
		n=new BigInteger(s);
		for(BigInteger i=BigInteger.ZERO;!i.equals(n);i=i.add(BigInteger.ONE)){
			s=in.next();
			s=s.replaceAll("\\+","");
			a=new BigInteger(s);
			s=in.next();
			s=s.replaceAll("\\+","");
			b=new BigInteger(s);
			System.out.println(a.add(b));
		}
	}
}
