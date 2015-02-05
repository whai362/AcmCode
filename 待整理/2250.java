import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int i,j;
		while(in.hasNext()){
		int cnt1=0,cnt2=0;
		String[] ans=new String[105],t1=new String[105],t2=new String[105];
		String tmp;
		while(in.hasNext()){
			tmp=in.next();
			if(tmp.equals("#")) break;
			t1[cnt1++]=tmp;
		}
		while(in.hasNext()){
			tmp=in.next();
			if(tmp.equals("#")) break;
			t2[cnt2++]=tmp;
		}
		int[][] dp=new int[cnt1+1][cnt2+1];
		int[][] f=new int[cnt1+1][cnt2+1];
		for(i=1;i<=cnt1;++i){
			for(j=1;j<=cnt2;++j){
				if(t1[i-1].equals(t2[j-1])){
					dp[i][j]=dp[i-1][j-1]+1;
					f[i][j]=0;
				}
				else{
					if(dp[i-1][j]>=dp[i][j-1]){
						dp[i][j]=dp[i-1][j];
						f[i][j]=1;
					}
					else{
						dp[i][j]=dp[i][j-1];
						f[i][j]=2;
					}
				}
			}
		}
		//System.out.println(dp[cnt1][cnt2]);
		int cnt=0;
		i=cnt1;
		j=cnt2;
		while(i>0 && j>0){
			if(f[i][j]==0){
				ans[cnt++]=t1[i-1];
				--i;
				--j;
			}
			else if(f[i][j]==1)
				--i;
			else
				--j;
		}
		//System.out.println(cnt);
		System.out.print(ans[cnt-1]);
		for(i=cnt-2;i>=0;--i){
			System.out.print(" "+ans[i]);
		}
		System.out.print("\n");
		}
	}
}
