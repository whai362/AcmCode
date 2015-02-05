#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 105
struct dev{
	int b,p,type;
}d[N*N];
struct table{
	int cnt,b[N],p[N];
}t[N];	//在第n组里，到b带宽至少要花多少钱p
int cnt,flag,_min[N],p0,p[N];	//p0和p[N]存着上一次查询到哪
bool cmp(dev d1,dev d2){
	return d1.b>d2.b;
}
int get_p(int i,int b){	//获取在第i组，b带宽至少要花多少钱
	while(p[i]>=0 && t[i].b[p[i]]<b) --p[i];
	if(p[i]>=0) return t[i].p[p[i]];
	else{
		flag=1;	//达不到b带宽，查询失败
		return 0;
	}
}
int main(){
	int m,n,T;
	double _max,tmp;
	int i,j;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	cnt=flag=0;
	_max=0;
	memset(_min,0x3f,sizeof(_min));
	for(i=0;i<n;++i)
		t[i].cnt=0;
	for(i=0;i<n;++i){
		scanf("%d",&m);
		for(j=0;j<m;++j){
			scanf("%d%d",&d[cnt].b,&d[cnt].p);
			d[cnt++].type=i;
		}
	}
	sort(d,d+cnt,cmp);
	for(i=0;i<cnt;++i){	//生成table
		j=d[i].type;
		_min[j]=min(_min[j],d[i].p);
		if(!t[j].cnt){
			t[j].b[t[j].cnt]=d[i].b;
			t[j].p[t[j].cnt++]=_min[j];
		}
		else{
			if(d[i].b==t[j].b[t[j].cnt-1]){
				t[j].p[t[j].cnt-1]=_min[j];	
			}
			else{
				t[j].b[t[j].cnt]=d[i].b;
				t[j].p[t[j].cnt++]=_min[j];
			}
		}
	}
	p0=cnt-1;
	for(i=0;i<n;++i){
		p[i]=t[i].cnt-1;
	}
	for(;p0>=0;--p0){
		tmp=0;
		for(i=0;i<n;++i){
			if(!flag) tmp+=get_p(i,d[p0].b);
			else break;
		}
		if(flag) break;
		tmp=d[p0].b/tmp;
		if(tmp>_max) _max=tmp;
	}
	printf("%.3f\n",_max);	//poj不能用".lf",会wa
	}
	return 0;
}
