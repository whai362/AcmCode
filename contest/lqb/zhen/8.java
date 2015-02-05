import java.util.*;
class Main{
	static int Max(int a,int b){ return a>b?a:b; }
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int ans=0,a,b,i,j,_max=0,t1,t2,tmp;
		int[] hash=new int[1000005];
		a=in.nextInt();
		b=in.nextInt();
		for(i=0;i<=1000;++i){
			for(j=0;j<=1000;++j){
				tmp=i*a+j*b;
				hash[tmp]=1;
				_max=Max(_max,tmp);
			}
		}
		int cnt=0;
		for(i=1;i<=_max;++i){
			if(hash[i]==1 && hash[i-1]==1) ++cnt;
			else if(hash[i]==0){
				cnt=0;
				ans=i;
			}
			if(cnt>1000) break;
		}
		System.out.println(ans);
	}
}
