#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 10005
struct point{
	int x,y;
}p[N];
int sum[N];
int abs(int n){
	if(n<0) return -n;
	return n;
}
bool cmp1(point p1,point p2){
	return p1.y<p2.y;
}
bool cmp2(point p1,point p2){
	return p1.x<p2.x;
}
int main(){
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	sort(p,p+n,cmp1);
	int ans=0,mid=(n+1)/2-1;
	for(i=0;i<n;++i){
		ans+=abs(p[i].y-p[mid].y);
	}
	sort(p,p+n,cmp2);
	int x0=p[0].x,pos,ansx;
	pos=x0+1;
	sum[0]=0;
	for(i=1;i<n;++i){
		sum[i]=sum[i-1]+pos-p[i].x;
	}
	ansx=abs(sum[n-1]);
	for(i=1;i<n;++i){
		int tmp=abs(sum[i-1]+i*(p[i].x-x0-i));
		tmp+=abs(sum[n-1]-sum[i]-(n-1-i)*(p[i].x-x0-i));
		cout<<i<<' '<<tmp<<endl;
	}
	return 0;
}
