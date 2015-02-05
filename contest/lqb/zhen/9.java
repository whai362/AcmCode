import java.util.*;
class Main{
	static int e,n,_max;
	static int[] vis=new int[100005],head=new int[100005];
	static edge[] p=new edge[200005];
	static void clear(){
		int i;
		for(i=0;i<2*n+5;++i){
			p[i]=new edge();
			head[i]=-1;
		}
		e=0;
	}
	static void addnode(int u,int v,int c){
		p[e].v=v;
		p[e].c=c;
		p[e].next=head[u];
		head[u]=e++;
	}
	static void dfs(int k,int dis){
		int i;
		vis[k]=1;
		if(dis>_max) _max=dis;
		for(i=head[k];i+1!=0;i=p[i].next){
			if(vis[p[i].v]==0){
				dfs(p[i].v,dis+p[i].c);
			}
		}
		vis[k]=0;
	}
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int i,p,q,d;
		n=in.nextInt();
		clear();
		for(i=0;i<n-1;++i){
			p=in.nextInt();
			q=in.nextInt();
			d=in.nextInt();
			addnode(p,q,d);
			addnode(q,p,d);
		}
		for(i=1;i<=n;++i){
			dfs(i,0);
		}
		System.out.println(((11+11+_max-1)*_max)/2);
	}
}
class edge{
	int v,c,next;
};
