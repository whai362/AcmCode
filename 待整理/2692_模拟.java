import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int cnt,e=0,i,j,_max,_min,n,w=0;
		int[] v=new int[25];
		int[] p=new int[1005];
		int[][] b=new int[1005][25];
		String[] name=new String[25];
		n=in.nextInt();
		in.nextLine();
		cnt=0;
		_max=0;
		_min=0x3f3f3f3f;
		for(i=0;i<=n;++i)
			v[i]=0;
		for(i=0;i<n;++i){
			name[i]=in.nextLine();
		}
		while(in.hasNext()){
			for(i=0;i<n;++i){
				b[cnt][i]=in.nextInt();
			}
			++cnt;
		}
		for(i=0;i<cnt;++i)
			p[i]=0;
		for(i=0;i<cnt;++i)
			v[b[i][p[i]]]++;
		while(true){
			for(i=1;i<=n;++i){
				if(v[i]>=0 && v[i]>_max){
					_max=v[i];
				}
				if(v[i]>=0 && v[i]<_min){
					_min=v[i];
				}
			}
			if(_max*2>cnt || _max==_min) break;
			else{
				for(i=1;i<=n;++i){
					if(v[i]==_min) v[i]=-1;
				}
				_min=0x3f3f3f3f;
			}
			for(i=0;i<cnt;++i){
				if(v[b[i][p[i]]]<0){
					while(p[i]<n && v[b[i][p[i]]]<0)
						++p[i];
					if(p[i]<n){
						++v[b[i][p[i]]];
					}
				}
			}
		}
		for(i=0;i<n;++i){
			for(i=1;i<=n;++i)
				if(v[i]==_max)
					System.out.println(name[i-1]);
		}
	}
}

