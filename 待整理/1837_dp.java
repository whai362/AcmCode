import java.util.*;
class Main{
	public static final int M=15006;
	public static final int x0=7503;
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int c,g;
		int i,j,k;
		c=in.nextInt();
		g=in.nextInt();
		int[] l=new int[c];
		int[] w=new int[g];
		for(i=0;i<c;++i)
			l[i]=in.nextInt();
		for(i=0;i<g;++i)
			w[i]=in.nextInt();
		int[][] dp=new int[M][g+1];
		dp[x0][0]=1;
		for(i=0;i<g;++i){
			for(j=0;j<c;++j){
				int t=w[i]*l[j];
				for(k=0;k<M;++k){
					if(dp[k][i]!=0){
						dp[k+t][i+1]+=dp[k][i];
					}
				}
			}
		}
		System.out.println(dp[x0][g]);
	}
}
