import java.util.*;
class Main{
	public static final long MOD=1000000007;
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		int i,j,k,l,r,n,m,t;
		t=in.nextInt();
		for(k=0;k<t;++k){
		n=in.nextInt();
		m=in.nextInt();
		long[] a=new long[n];
		long[] f=new long[n];
		for(i=0;i<n;++i){
			a[i]=in.nextLong();
		}
		for(i=0;i<m;++i){
			l=in.nextInt();
			r=in.nextInt();
			f[l-1]=a[l-1];
			if(l<n) f[l]=a[l];
			for(j=l+1;j<r;++j){
				f[j]=(f[j-1]+f[j-2]*a[j]);
			}
			System.out.println(f[r-1]%MOD);
		}
		}
	}
}
