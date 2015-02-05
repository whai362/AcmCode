import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int i,t;
		long ans,l,n;
		t=in.nextInt();
		for(l=0;l<t;++l){
			n=in.nextLong();
			ans=0;
			for(i=5;i<=n;i*=5){
				ans+=n/i;
			}
			System.out.println(ans);
		}
	}
}
