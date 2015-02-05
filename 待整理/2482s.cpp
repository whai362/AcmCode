#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 20010;
int cover[maxn<<2],Max[maxn<<2];
struct seg{
	double l,r,h;
	int flag;
	seg(){}
	seg(double _l,double _r,double _h,int _flag):l(_l),r(_r),h(_h),flag(_flag){}
	bool operator <(const seg &cmp) const {
		if(h==cmp.h) return flag<cmp.flag;
		return h<cmp.h;
	}
}horizontal_seg[maxn];
int ans;
double x[maxn];
int max(int a,int b){
	return a>b?a:b;
}
void pushdown(int rt){
	if(cover[rt]){
		cover[rt<<1]+=cover[rt];
		cover[rt<<1|1]+=cover[rt];
		Max[rt<<1]+=cover[rt];
		Max[rt<<1|1]+=cover[rt];
		cover[rt]=0;
	}
}
void pushup(int rt){
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
void update(int L,int R,int c,int l,int r,int rt){
	if(L<=l&&r<=R){
		cover[rt]+=c;
		Max[rt]+=c;
		return ;
	}
	pushdown(rt);
	int m=(l+r)>>1;
	if(L<=m) update(L,R,c,lson);
	if(R>m) update(L,R,c,rson);
	pushup(rt);
}
int bin(double key,int n,double x[]){
	int l=0,r=n-1,mid,best=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(x[mid]<=key){
			best=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return best;
}
int main(){
	int n,i,j,k,c;
	double W,H;
	double a,b;
	while(scanf("%d%lf%lf",&n,&W,&H)!=EOF){
		int tot=0;
		ans=0;
		memset(cover,0,sizeof(cover));
		memset(Max,0,sizeof(Max));
		for(i=1;i<=n;i++){
			scanf("%lf%lf%d",&a,&b,&c);
			x[tot]=a;
			horizontal_seg[tot++]=seg(a,a+W,b,c);
			x[tot]=a+W;
			horizontal_seg[tot++]=seg(a,a+W,b+H,-c);
		}
		sort(x,x+tot);
		for(i=1,k=1;i<tot;i++)
		  if(x[i]!=x[i-1]) x[k++]=x[i];
		//cout<<k<<endl;
		sort(horizontal_seg,horizontal_seg+tot);
		for(i=0,j=0;i<tot-1;i++){
			int left=bin(horizontal_seg[i].l,k,x);
			int right=bin(horizontal_seg[i].r,k,x)-1;
			//cout<<"!"<<left<<' '<<right<<' '<<horizontal_seg[i].flag<<endl;
			int sss;
			cin>>sss;
			update(left,right,horizontal_seg[i].flag,0,k-1,1);
			if(Max[1]>ans) ans=Max[1];
		}
		//printf("%d\n",ans);
	}
	return 0;
}
/*
24 83
46 87
82 50
33 36
5 62
*/

