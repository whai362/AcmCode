#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 102
struct point{
	int x,y,c;
};
point p[maxn*maxn],_set[maxn*maxn];
int hx[maxn],hy[maxn];
bool cmp1(point p1,point p2){
 return p1.c<p2.c;
}
bool cmp2(point p1,point p2){
 return p1.c>p2.c;
}
int main(){
	int m,n,t;
	int i,j;
	cin>>t;
	for(int l=1;l<=t;++l){
		scanf("%d%d",&m,&n);
		int cnt1=0;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++){
				int a;
				scanf("%d",&a);
				p[cnt1].x=i;
				p[cnt1].y=j;
				p[cnt1++].c=a;
			}
		memset(hx,0,sizeof(hx));
		memset(hy,0,sizeof(hy));
		sort(p,p+cnt1,cmp1);
		int cnt2=0;
		int total=m+n;
		i=0;
		while(total>0){
			if(hx[p[i].x]==0) --total;
			if(hy[p[i].y]==0) --total;
			++hx[p[i].x];
			++hy[p[i].y];
			_set[cnt2++]=p[i++];
		}
		sort(_set,_set+cnt2,cmp2);
		int ans=0;
		for(i=0;i<cnt2;++i){
			if(hx[_set[i].x]>1&&hy[_set[i].y]>1){
				--hx[_set[i].x];
				--hy[_set[i].y];
			}
			else ans+=_set[i].c;
		}
		printf("Case %d: %d\n",l,ans);
	}
	return 0;
}
