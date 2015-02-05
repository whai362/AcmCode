import java.util.*;
class Main{
	public static final int N=50000;
	static int max(int a,int b){ return a>b?a:b; }
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int ans,c,n,y,d;
		int i,j,k,l,len,_max,t;
		n=in.nextInt();
		for(l=0;l<n;++l){
			c=in.nextInt();
			ans=c;
			c/=1000;
			y=in.nextInt();
			d=in.nextInt();
			_max=0;
			int[][] b=new int[d][2];
			for(i=0;i<d;++i){
				b[i][0]=in.nextInt();
				b[i][1]=in.nextInt();
				b[i][0]/=1000;
				if(_max<b[i][0]) _max=b[i][0];
			}
			int[] dp=new int[N];
			for(i=0;i<d;++i){
				for(j=b[i][0];j<=c;++j){
					if(dp[j]<dp[j-b[i][0]]+b[i][1]){
						dp[j]=dp[j-b[i][0]]+b[i][1];
					}
				}
			}
			for(i=0;i<y;++i){
				ans+=dp[c];
				t=ans/1000;
				for(j=0;j<d;++j){
					for(k=max(c-_max,b[j][0]);k<=t;++k){
						if(dp[k]<dp[k-b[j][0]]+b[j][1]){
							dp[k]=dp[k-b[j][0]]+b[j][1];
						}
					}
				}
				c=t;
			}
			System.out.println(ans);
		}
	}
}
