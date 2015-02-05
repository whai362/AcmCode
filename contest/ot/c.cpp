#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100005
#define INF 100000000000LL
struct Data{
	int x,id;
	long long p;
}d[N];
long long hash[N];
bool vis[N];
bool cmp1(Data d1,Data d2){
	return d1.p<d2.p;
}
bool cmp2(Data d1,Data d2){
	return d1.id<d2.id;
}
struct node{
	int l,r,m;
	int lit,rit;
	long long dis;
}v[N*3];
void bulid(int l,int r,int n){
	int mid=(l+r)>>1;
	v[n].l=l,v[n].r=r,v[n].m=mid;
	v[n].lit=N;
	v[n].rit=-1;
	v[n].dis=INF;
	if(l==r) return;
	bulid(l,mid,2*n);
	bulid(mid+1,r,2*n+1);
}
void up(int n){
	v[n].lit=min(v[2*n].lit,v[2*n+1].lit);
	v[n].rit=max(v[2*n].rit,v[2*n+1].rit);
	v[n].dis=min(v[2*n].dis,v[2*n+1].dis);
	if(v[n].rit!=-1 && v[n].lit!=N && v[n].lit!=v[n].rit){
		//cout<<'!'<<v[n].lit<<' '<<v[n].rit<<' '<<hash[v[2*n+1].lit]<<' '<<hash[v[2*n].rit]<<endl;
		//cout<<"?"<<hash[0]<<endl;
		v[n].dis=min(v[n].dis,hash[v[n].rit]-hash[v[n].lit]);
	}
	if(v[2*n].rit!=-1 && v[2*n+1].lit!=N && v[2*n+1].lit!=v[2*n].rit){
		//cout<<'!'<<v[2*n+1].lit<<' '<<v[2*n].rit<<' '<<hash[v[2*n+1].lit]<<' '<<hash[v[2*n].rit]<<endl;
		//cout<<"?"<<hash[0]<<endl;
		v[n].dis=min(v[n].dis,hash[v[2*n+1].lit]-hash[v[2*n].rit]);
	}
}
void insert(int x,int n){
	if(v[n].l==v[n].r){
		v[n].lit=v[n].rit=x;
		v[n].dis=INF;
		//cout<<v[n].l<<' '<<v[n].r<<' '<<v[n].lit<<' '<<v[n].rit<<' '<<v[n].dis<<endl;
		return;
	}
	if(x<=v[n].m)
	  insert(x,2*n);
	else
	  insert(x,2*n+1);
	up(n);
	//cout<<v[n].l<<' '<<v[n].r<<' '<<v[n].lit<<' '<<v[n].rit<<' '<<v[n].dis<<endl;
}
int main(){
	int i,n;
	char op[15];
	while(scanf("%d",&n)!=EOF){
	memset(hash,0,sizeof(hash));
	memset(vis,0,sizeof(vis));
	for(i=0;i<n;++i){
		scanf("%s",op);
		if(op[0]=='A'){
			scanf("%lld",&d[i].p);
			d[i].id=i;
		}
		else{
			d[i].p=INF;
			d[i].id=i;
		}
	}
	bulid(0,n,1);
	sort(d,d+n,cmp1);
	d[0].x=0;
	hash[0]=d[0].p;
	for(int i=1;i<n;++i){
		if(d[i].p!=INF){
			if(d[i].p==d[i-1].p) d[i].x=d[i-1].x;
			else d[i].x=d[i-1].x+1;
			hash[d[i].x]=d[i].p;
		}
		else break;
	}
	sort(d,d+n,cmp2);
	int flag=1;
	for(int i=0;i<n;++i){
		if(d[i].p==INF){
			//cout<<'!'<<endl;
			if(flag)
				printf("%lld\n",v[1].dis);
			else
				puts("0");
		}
		else{
			//cout<<d[i].p<<endl;
			if(vis[d[i].x]==0){
				insert(d[i].x,1);
				vis[d[i].x]=1;
			}
			else{
				flag=0;
			}
		}
	}
	}
	return 0;
}
