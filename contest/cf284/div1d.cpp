/*cf284div1d
  题意：有n+1个城市，n条路，每条路连着第n个和第n+1个城市，然后每条路有一个路况信息a[i]，如果现在的时刻t，t%a[i]==0，则不能通过这条路，要等到下一秒t+1，如果现在时刻t，t%a[i]!=0，则通过这条路，花费时间为1。现在有q个操作，对于美国操作有两种类型：
  A x y 询问从城市x到城市y要花费多少时间
  C x y 把a[x]改为y
  限制：1 <= n <= 1e5 , 2 <= ai <= 6 , 1 <= q <= 1e5
  思路：线段树
  要解决的问题是O(logn)查询出来从x到y的时间。
  因为ai只有 2 3 4 5 6 这几个取值，最小公倍数为60，也就是说无论是哪段路都可以以60为周期。
  所以对路建树
  线段树里面有一个t[60]的数组，表示在l城市在t时刻出发到r+1城市要花的时间。
  考虑好向上维护的情况就能过了。
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int a[N];
struct Seg{
	int l,r,mid;
	int t[60];
}seg[3*N];
void up(int n){
	for(int i=0;i<60;++i){
		int tmp=i+seg[2*n].t[i];	//注意的地方
		seg[n].t[i]=tmp-i+seg[2*n+1].t[tmp%60];
	}
}
void build(int l,int r,int n){
	seg[n].l=l; seg[n].r=r; seg[n].mid=(l+r)>>1;
	if(l==r){
		for(int i=0;i<60;++i)
			if(i%a[l]==0) seg[n].t[i]=2;
			else seg[n].t[i]=1;
		return ;
	}
	build(l,seg[n].mid,2*n);
	build(seg[n].mid+1,r,2*n+1);
	up(n);
}
void update(int u,int n,int x){
	if(seg[n].l==seg[n].r){
		a[u]=x;
		for(int i=0;i<60;++i)
			if(i%a[u]==0) seg[n].t[i]=2;
			else seg[n].t[i]=1;
		return ;
	}
	if(u<=seg[n].mid) update(u,2*n,x);
	else update(u,2*n+1,x);
	up(n);
}
int query(int l,int r,int n,int t){
	if(l <= seg[n].l && seg[n].r <= r){
		return t+seg[n].t[t%60];
	}
	if(seg[n].mid>=l) t=query(l,r,2*n,t);
	if(seg[n].mid<r) t=query(l,r,2*n+1,t);
	return t;
}
void debug(int n){
	cout<<"---"<<endl;
	for(int i=1;i<=n;++i)
		cout<<query(i,i,1,0)<<' ';
	cout<<endl;
	cout<<"---"<<endl;
}
void debug1(int n){
	cout<<seg[n].l<<' '<<seg[n].r<<' '<<seg[n].t[0]<<endl;
	if(seg[n].l==seg[n].r) return ;
	debug1(2*n);
	debug1(2*n+1);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	build(1,n,1);
	int m;
	scanf("%d",&m);
	char op[2];
	int u,v;
	for(int i=0;i<m;++i){
		scanf("%s%d%d",op,&u,&v);
		if(op[0]=='A'){
			printf("%d\n",query(u,v-1,1,0));
		}
		else{
			update(u,1,v);
		}
	}
	return 0;
}
