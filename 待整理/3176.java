import java.util.*;
class Main{
	public static int[][] a=new int[355][355];
	static int Max(int a,int b){ return a>b?a:b; }
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int n;
		int ans=0,i,j;
		n=in.nextInt();
		for(i=0;i<n;++i){
			for(j=0;j<=i;++j){
				a[i][j]=in.nextInt();
			}
		}
		for(i=1;i<n;++i){
			for(j=0;j<=i;++j){
				if(j==0) a[i][0]+=a[i-1][0];
				else if(j==i) a[i][j]+=a[i-1][j-1];
				else a[i][j]+=Max(a[i-1][j-1],a[i-1][j]);
			}
		}
		for(i=0;i<n;++i){
			if(ans<a[n-1][i]) ans=a[n-1][i];
		}
		System.out.println(ans);
	}
}
