import java.util.*;
class Main{
	static int Max(int a,int b){ return a>b?a:b; }
	static int Min(int a,int b){ return a<b?a:b; }
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int cnt=0,i,j,_max,_min,n;
		n=in.nextInt();
		int[] p=new int[n];
		for(i=0;i<n;++i){
			p[i]=in.nextInt();
		}
		for(i=0;i<n;++i){
			_max=0;
			_min=0x3f3f3f3f;
			for(j=i;j<n;++j){
				_max=Max(_max,p[j]);
				_min=Min(_min,p[j]);
				if(_max-_min==j-i) ++cnt;
			}
		}
		System.out.println(cnt);
	}
}
