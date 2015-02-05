import java.util.*;
class Main{
	static final int INF=0x3f3f3f3f;
	static int[][][] dp=new int[405][25][25];
	static int Max(int a,int b){ return a>b?a:b; }
	static int Min(int a,int b){ return a<b?a:b; }
	static int dfs(int m,int w,int h){
		int i,j;
		//System.out.println(m+" "+w+" "+h);
		if(dp[m][w][h]!=0)
			return dp[m][w][h];
		else if(m==0){
			dp[m][w][h]=w*h;
		}
		else{
			int tmp=w/2;
			dp[m][w][h]=INF;
			for(i=1;i<=tmp;++i){
				for(j=0;j<m;++j){
					dp[m][w][h]=Min(dp[m][w][h],Max(dfs(j,i,h),dfs(m-1-j,w-i,h)));
				}
			}
			tmp=h/2;
			for(i=1;i<=tmp;++i){
				for(j=0;j<m;++j){
					dp[m][w][h]=Min(dp[m][w][h],Max(dfs(j,w,i),dfs(m-1-j,w,h-i)));
				}
			}
		}
		return dp[m][w][h];
	}
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int w,h,m;
		int i,j,k;
		while(true){
		w=in.nextInt();
		h=in.nextInt();
		m=in.nextInt();
		if(w==0 && h==0 && m==0) break;
		System.out.println(dfs(m-1,w,h));
		}
	}
}
