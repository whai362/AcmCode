import java.util.*;
class Main{
	static int gcd(int a,int b){
		if(b!=0) return gcd(b,a%b);
		return a;
	}
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int a,b,c,t;
		a=in.nextInt();
		b=in.nextInt();
		c=in.nextInt();
		t=a*b/gcd(a,b);
		System.out.println(t*c/gcd(t,c));
	}
}
