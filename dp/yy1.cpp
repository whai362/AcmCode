#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define PB push_back
const int N=3005;
struct INFO{
	int a,b;
}a[30];
int ALL;
char str[N];
char tab[30],h[30],cnt=0;
vector<int> vec[30];
int q[N];
struct Seg{
	int l,r,mid;
	int min;
}seg[3*N];
void up(int n){
	seg[n].min=min(seg[2*n].min,seg[2*n+1].min);
}
void build(int l,int r,int n){
	seg[n].l=l,seg[n].r=r;
	int mid=(l+r)>>1;
	seg[n].mid=mid;
	if(l==r){
		seg[n].min=ALL;
		return ;
	}
	build(l,mid,2*n);
	build(mid+1,r,2*n+1);
	up(n);
}
int query(int l,int r,int n){
	if(l==seg[n].l && r==seg[n].r)
		return seg[n].min;
	if(r<=seg[n].mid) return query(l,r,2*n);
	else if(l>seg[n].mid) return query(l,r,2*n+1);
	else return min(query(l,seg[n].mid,2*n),query(seg[n].mid+1,r,2*n+1));
}
void update(int p,int x,int n){
	if(seg[n].l==seg[n].r){
		seg[n].min=min(seg[n].min,x);
		return ;
	}
	if(p<=seg[n].mid) update(p,x,2*n);
	else update(p,x,2*n+1);
	up(n);
}
int gao(int n,int m){
	ALL=0;
	cnt=0;
	memset(h,-1,sizeof(h));
	for(int i=0;i<n;++i)
		vec[i].clear();
	for(int i=0;i<m;++i){
		ALL+=a[str[i]-'a'].b;
		if(h[str[i]-'a']==-1){
			h[str[i]-'a']=cnt;
			tab[cnt++]=str[i]-'a';
		}
		vec[h[str[i]-'a']].PB(i);
	}
	for(int i=0;i<n;++i)
		vec[i].PB(m);
	build(0,m,1);
	int ans=ALL;
	
	for(int i=0;i<m;++i){
		cout<<i<<":"<<endl;
		int j=h[str[i]-'a'];
		for(int k=0;k<vec[j].size()-1;++k){
			if(vec[j][k]<i) continue;
			q[k]=query(vec[j][k]+1,m,1);
			cout<<i<<' '<<vec[j][k]<<' '<<q[k]<<"->";
			if(vec[j][k]==i)
				q[k]-=a[tab[j]].b;
			else
				q[k]-=2*a[tab[j]].b;
			cout<<q[k]<<endl;
			ans=min(q[k],ans);
		}
		q[vec[j].size()-1]=query(m,m,1)+a[tab[j]].a-a[tab[j]].b;
		cout<<i<<' '<<m<<' '<<query(m,m,1)<<"->"<<q[vec[j].size()-1]<<endl;
		ans=min(q[vec[j].size()-1],ans);
		for(int k=0;k<vec[j].size();++k){
			if(vec[j][k]<i) continue;
			update(vec[j][k],q[k],1);
		}
	}
	cout<<endl;
	return ans;
}
char tmp[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",str);
	for(int i=0;i<n;++i){
		char ch[3];
		int t1,t2;
		scanf("%s%d%d",ch,&t1,&t2);
		a[ch[0]-'a'].a=t1; a[ch[0]-'a'].b=t2;
	}
	int ans=gao(n,m);
	for(int i=m-1;i>=0;--i){
		tmp[i]=str[m-1-i];
	}
	for(int i=0;i<m;++i)
		str[i]=tmp[i];
	ans=min(ans,gao(n,m));
	printf("%d\n",ans);
	return 0;
}
