#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 10005
struct seg{
	long long l,r,h;
	int b;
	seg(){}
	seg(long long _l,long long _r,long long _h,int _b){
		l=_l,r=_r,h=_h,b=_b;
	}
}s[2*N];
struct node{
	int l,r,mid,add,_max;
}v[7*N];
int cnt;
long long _x[2*N];
bool cmp(seg s1,seg s2){
	if(s1.h<s2.h || (s1.h==s2.h && s1.b<s2.b)) return true;
	return false;
}
void build(int l,int r,int rt){
	int mid=(l+r)>>1;
	v[rt].l=l,v[rt].r=r,v[rt].mid=mid,v[rt].add=v[rt]._max=0;
	if(l==r) return ;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
}
void update(int l,int r,int b,int rt){
	if(l<=v[rt].l&&v[rt].r<=r){
		v[rt].add+=b;
		v[rt]._max+=b;
		return ;
	}
	if(v[rt].add){
		v[rt<<1].add+=v[rt].add;
		v[rt<<1]._max+=v[rt].add;
		v[rt<<1|1].add+=v[rt].add;
		v[rt<<1|1]._max+=v[rt].add;
		v[rt].add=0;
	}
	if(l<=v[rt].mid) update(l,r,b,rt<<1);
	if(r>v[rt].mid) update(l,r,b,rt<<1|1);
	v[rt]._max=max(v[rt<<1]._max,v[rt<<1|1]._max);
}
int find(long long key){
	int l=0,r=cnt,mid=(l+r)>>1;
	while(l!=r){
		if(key<=_x[mid]) r=mid;
		else l=mid+1;
		mid=(l+r)>>1;
	}
	return l;
}
int main(){
	int n,l,r,b,_max;
	long long w,h,x,y;
	int i;
	while(scanf("%d%I64d%I64d",&n,&w,&h)!=EOF){
	cnt=0;
	_max=0;
	for(i=0;i<n;++i){
		scanf("%I64d%I64d%d",&x,&y,&b);
		s[cnt]=seg(x,x+w,y,b);
		_x[cnt++]=x;
		s[cnt]=seg(x,x+w,y+h,-b);
		_x[cnt++]=x+w;
	}
	sort(_x,_x+cnt);
	cnt=unique(_x,_x+cnt)-_x;
	sort(s,s+2*n,cmp);
	build(0,cnt,1);
	for(i=0;i<2*n-1;++i){
		l=find(s[i].l);
		r=find(s[i].r)-1;
		update(l,r,s[i].b,1);
		_max=max(_max,v[1]._max);
	}
	cout<<_max<<endl;
	}
	return 0;
}
