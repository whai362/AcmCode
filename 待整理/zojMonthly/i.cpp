#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 300005
struct node{
	int l,r,m,g0,g1;
}v[5*N];
struct light{
	int v,s;
	light(int v,int s){
		this->v=v;
		this->s=s;
	}
};
vector<light> li;
int cnt;
void build(int l,int r,int n){
	int mid=(l+r)>>1;
	v[n].l=l,v[n].r=r,v[n].m=mid;
	if(l==r){
		return ;
	}
	build(l,mid,2*n);
	build(mid+1,r,2*n+1);
}
int query(int l,int r,int s,int n){
	if(s){
		if(l==r){
			if(li[l-1].s) return li[l-1].v;
			else return 0;
		}
		if(r<=v[n].m) query(l,r,s,2*n);
		else if(l>v[n].m) query(l,r,s,2*n+1);
		else{
			int t1,t2;
			t1=query(l,v[n].m,s,2*n);
			t2=query(v[n].m+1,r,s,2*n+1);
			if(t1 && t2){
				return __gcd(t1,t2);
			}
			else return max(t1,t2);
		}
	}
	else{
		if(l==r){
			if(!li[l-1].s) return li[l-1].v;
			else return 0;
		}
		if(r<=v[n].m) query(l,r,s,2*n);
		else if(l>v[n].m) query(l,r,s,2*n+1);
		else{
			int t1,t2;
			t1=query(l,v[n].m,s,2*n);
			t2=query(v[n].m+1,r,s,2*n+1);
			if(t1 && t2){
				return __gcd(t1,t2);
			}
			else return max(t1,t2);
		}
	}
}
void R(int n){
	li[n-1].s=!li[n-1].s;
}
void M(int i,int x){
	li[i-1].v=x;
}
void D(int n){
	int i;
	li.erase(li.begin()+n);
	--cnt;
}
void I(int n,int v,int s){
	int i;
	li.insert(li.begin()+n,light(v,s));
	++cnt;
}
int main(){
	int i,n,q;
	char op[2];
	while(scanf("%d%d",&n,&q)!=EOF){
		int a,b;
		li.clear();
		for(i=0;i<n;++i){
			scanf("%d%d",&a,&b);
			li.push_back(light(a,b));
		}
		cnt=n;
		build(1,300001,1);
		for(i=0;i<q;++i){
			int a,b,c;
			scanf("%s",op);
			if(op[0]=='Q'){
				scanf("%d%d%d",&a,&b,&c);
				int ans=query(a,b,c,1);
				if(ans) printf("%d\n",ans);
				else printf("-1\n");
			}
			else if(op[0]=='I'){
				scanf("%d%d%d",&a,&b,&c);
				I(a,b,c);
			}
			else if(op[0]=='D'){
				scanf("%d",&a);
				D(a);
			}
			else if(op[0]=='M'){
				scanf("%d%d",&a,&b);
				M(a,b);
			}
			else if(op[0]=='R'){
				scanf("%d",&a);
				R(a);
			}
		}
	}
	return 0;
}
