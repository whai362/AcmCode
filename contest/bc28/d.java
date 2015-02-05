import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	static final int N = 105;
	static boolean cmp(char[] a,char[] b,int len){
		if(len>b.length) return false;
		boolean ret=true;
		for(int i=0;i<len;++i){
			if(b[i]!=a[a.length-len+i]){
				ret=false;
				break;
			}
		}
		return ret;
	}
	static BigInteger toBigInt(char a[],int len){
		BigInteger ret=BigInteger.ZERO;
		for(int i=len-1;i>=0;--i)
			ret=ret.multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(a[i]-'0'));
		return ret;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String str;
		char[] A=new char[N];
		char[] B=new char[N];
		char[] aa=new char[N],bb=new char[N],
		ab=new char[N],ba=new char[N];
		BigInteger AA,BB,AB,BA;
		int ans;
		int T;
		T=in.nextInt();
		while(T-->0){
			str=in.next();
			A=str.toCharArray();
			str=in.next();
			B=str.toCharArray();
			for(int i=0;i<A.length;++i){
				if(cmp(A, A, i+1)) aa[i]='1';
				else aa[i]='0';
				if(cmp(A, B, i+1)) ab[i]='1';
				else ab[i]='0';
			}
			for(int i=0;i<B.length;++i){
				if(cmp(B, B, i+1)) bb[i]='1';
				else bb[i]='0';
				if(cmp(B, A, i+1)) ba[i]='1';
				else ba[i]='0';
			}
			/*System.out.println(aa);
			System.out.println(ab);
			System.out.println(bb);
			System.out.println(ba);*/
			AA=toBigInt(aa,A.length);
			BB=toBigInt(bb,B.length);
			AB=toBigInt(ab,A.length);
			BA=toBigInt(ba,B.length);
			/*System.out.println(AA);
			System.out.println(AB);
			System.out.println(BB);
			System.out.println(BA);*/
			ans=BB.subtract(BA).compareTo(AA.subtract(AB));
			if(ans==0) System.out.println("Fair");
			else if(ans>0) System.out.println("A");
			else System.out.println("B");
		}
	}
}
/*
3
10110
01011
*/
