import java.util.*;
class Main{
	static int ans,half,m,n;
	static int[][] _map=new int[15][15],vis=new int[15][15];
	static int _min(int a,int b){ return a<b?a:b; }
	static boolean ok(int x,int y){
		if(x>=0 && x<n && y>=0 && y<m) return true;
		return false;
	}
	static void dfs(int x,int y,int sum,int step){
		//System.out.println(x+" "+y+" "+_map[x][y]+" "+sum);
		//in.nextInt();
		sum+=_map[x][y];
		step++;
		vis[x][y]=1;
		if(sum==half){
			//System.out.println("!");
			ans=_min(ans,step);
			vis[x][y]=0;
			return ;
		}
		if(ok(x-1,y) && vis[x-1][y]==0) dfs(x-1,y,sum,step);
		if(ok(x+1,y) && vis[x+1][y]==0) dfs(x+1,y,sum,step);
		if(ok(x,y-1) && vis[x][y-1]==0) dfs(x,y-1,sum,step);
		if(ok(x,y+1) && vis[x][y+1]==0) dfs(x,y+1,sum,step);
		vis[x][y]=0;
		return ;
	}
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int i,j;
		m=in.nextInt();
		n=in.nextInt();
		ans=0x3f3f3f3f;
		for(i=0;i<n;++i){
			for(j=0;j<m;++j){
				_map[i][j]=in.nextInt();
				half+=_map[i][j];
			}
		}
		if(half%2==1) System.out.println(0);
		else{
			half/=2;
			dfs(0,0,0,0);
			if(ans==0x3f3f3f3f) System.out.println(0);
			else System.out.println(ans);
		}
	}
}
