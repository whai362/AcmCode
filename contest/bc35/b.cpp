#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define LL __int64
#define PB push_back
const int N=1e5+5;
vector<int> G[N];
int in[N];
int ans[N],cnt;
void init(){
	memset(in,0,sizeof(in));
	cnt=0;
	for(int i=0;i<N;++i)
		G[i].clear();
}

priority_queue<int> q;
void print(int n){
	for(int i=1;i<=n;++i){
		cout<<in[i]<<' ';
	}
	cout<<endl;

}
void In(int &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

void Out(int x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}

int main(){
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		init();
		int u,v;
		for(int i=0;i<m;++i){
			//scanf("%d%d",&u,&v);
			In(u);
			In(v);
			G[u].PB(v);
			++in[v];
		}
		for(int i=1;i<=n;++i){
			if(in[i]<=k) q.push(i);
		}
		while(!q.empty() && k){	//一定要!q.empty(),下附数据
			int now=q.top();
			q.pop();
			//cout<<k<<' '<<now<<' '<<in[now]<<endl;
			if(in[now]<=k && in[now]!=-1){	//一定要in[now]!=-1，下附数据
				k-=in[now];
				ans[cnt++]=now;
				in[now]=-1;
				for(int i=0;i<G[now].size();++i){
					int ch=G[now][i];
					if(in[ch]<0) continue;
					if(in[ch]>k){
						--in[ch];
						if(in[ch]<=k) q.push(ch);
					}
					else{
						--in[ch];
					}
				}
				//cout<<"k"<<' '<<k<<endl;
				//print(n);
			}
		}
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;++i){
			if(in[i]==0){
				q.push(i);
				in[i]==-1;
			}
		}
		while(!q.empty()){
			int now=q.top();
			q.pop();
			ans[cnt++]=now;
			for(int i=0;i<G[now].size();++i){
				int ch=G[now][i];
				if(in[ch]>0){
					--in[ch];
				}
				if(in[ch]==0){
					q.push(ch);
					in[ch]=-1;
				}
			}
		}
		for(int i=0;i<cnt;++i){
			Out(ans[i]);
			if(i==cnt-1) puts("");
			else putchar(' ');
			//printf("%d%c",ans[i],i==cnt-1?'\n':' ');
		}
	}
	return 0;
}
/*
5 5 4
1 3
2 3
4 3
5 3
4 5
*/
