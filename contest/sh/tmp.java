import java.util.*;
import java.math.*;

class Main
{
	public static void main(String[] args) 
	{
		Scanner in=new Scanner(System.in);
		int len1,len2,T;
		String str,out;
		char[] s1=new char[1005],s2=new char[1005];
		BigInteger a,b,ans,tmp;
		T=in.nextInt();
		for(int t=1;t<=T;++t){
			str=in.next();
			s1=str.toCharArray();
			str=in.next();
			s2=str.toCharArray();
			a=BigInteger.valueOf(0);
			b=BigInteger.valueOf(0);
			len1=s1.length;
			for(int i=0;i<len1;++i){
				if(s1[i]=='0') a=a.multiply(BigInteger.valueOf(2));
				else a=a.multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(1));
			}
			len2=s2.length;
			for(int i=0;i<len2;++i){
				if(s2[i]=='0') b=b.multiply(BigInteger.valueOf(2));
				else b=b.multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(1));
			}
			ans=a.gcd(b);
			out="";
			while(!ans.equals(BigInteger.valueOf(0))){
				tmp=ans.mod(BigInteger.valueOf(2));
				out=out+tmp.toString();
				ans=ans.divide(BigInteger.valueOf(2));
			}
			out=new StringBuffer(out).reverse().toString(); 
	        System.out.println("Case #"+t+": "+out);
		}
	}
}

