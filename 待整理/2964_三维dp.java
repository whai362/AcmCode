import java.util.*;
class Main{
	static char[][] _map=new char[105][105];
	static int w,h;
	static int[][][] dp=new int[205][105][105];
	static int _max(int a,int b){ return a>b?a:b; }
	static boolean ok(int i,int j){
		if(i>=0 && i<h && j>=0 && j<w){
			if(_map[i][j]=='#') return false;
			else return true;
		}
		return false;
	}
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int ans,i,j,k,l,t,tmp,x1,y1,x2,y2;
		String str;
		t=in.nextInt();
		for(l=0;l<t;++l){
			w=in.nextInt();
			h=in.nextInt();
			for(i=0;i<h;++i){
				str=in.next();
				_map[i]=str.toCharArray();
			}
			for(i=0;i<w+h-1;++i)
				for(j=0;j<h;++j)
					for(k=0;k<h;++k)
						dp[i][j][k]=0;
			for(i=0;i<w+h-1;++i){
				for(j=0;j<h;++j){
					for(k=0;k<h;++k){
						x1=j;
						y1=i-j;
						x2=k;
						y2=i-k;
						if(ok(x1,y1) && ok(x2,y2)){
							if(ok(x1,y1-1) && ok(x2,y2-1))
								dp[i][j][k]=_max(dp[i][j][k],dp[i-1][j][k]);
							if(ok(x1-1,y1) && ok(x2,y2-1))
								dp[i][j][k]=_max(dp[i][j][k],dp[i-1][j-1][k]);
							if(ok(x1,y1-1) && ok(x2-1,y2))
								dp[i][j][k]=_max(dp[i][j][k],dp[i-1][j][k-1]);
							if(ok(x1-1,y1) && ok(x2-1,y2))
								dp[i][j][k]=_max(dp[i][j][k],dp[i-1][j-1][k-1]);
							if(x1==x2){
								if(_map[x1][y1]=='*')
									++dp[i][j][k];
							}
							else{
								if(_map[x1][y1]=='*')
									++dp[i][j][k];
								if(_map[x2][y2]=='*')
									++dp[i][j][k];
							}
						}
					}
				}
			}
			System.out.println(dp[w+h-2][h-1][h-1]);
		}
	}
}
