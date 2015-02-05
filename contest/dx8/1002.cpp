#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
#define eps 1e-10
#define pi 3.1415926
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{
	double x,y,v;
	int id;
};
double xmult(point p1,point p2,point p0){	
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
point p1,p2;
int graham_cp(const void* a,const void* b){
	double ret=xmult(*((point*)a),*((point*)b),p1);
	return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch){
	int i,k=0;
	for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
		if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
			p1=p[k=i];
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
		for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}

int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
	point* temp=new point[n];
	int s,i;
	_graham(n,p,s,temp);
	for (convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
		if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
			convex[n++]=temp[i];
	delete []temp;
	return n;
}
point in[510],p[510],convex[510];
int ans[510];
char out[510];
void init(){
	memset(ans,0,sizeof(ans));
	memset(out,0,sizeof(out));
	memset(in,0,sizeof(in));
	memset(p,0,sizeof(p));
	memset(convex,0,sizeof(convex));

}
int main(){
	int cas=0,n;
	double _max;
	while(scanf("%d",&n) && n){
		init();
		_max=0;
		for(int i=0;i<n;++i){
			scanf("%lf%lf%lf",&in[i].x,&in[i].y,&in[i].v);
			in[i].id=i;
			_max=max(_max,in[i].v);
		}
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				if(in[i].x==in[j].x && in[i].y==in[j].y && in[i].v==in[j].v){
					in[j].v=0;
					ans[i]=ans[j]=-1;
				}
			}
		}
		if(_max>0){
			int cnt=0;
			for(int i=0;i<n;++i){
				if(in[i].v==_max){
					p[cnt++]=in[i];
				}
			}
			if(cnt>=3){
				cnt=graham(cnt,p,convex);
				for(int i=0;i<cnt;++i){
					if(ans[convex[i].id]!=-1){
						ans[convex[i].id]=1;
					}
				}
			}
			else{
				for(int i=0;i<cnt;++i){
					if(ans[p[i].id]!=-1){
						ans[p[i].id]=1;
					}
				}
			}
		}
		memset(out,0,sizeof(out));
		for(int i=0;i<n;++i){
			if(ans[i]==1) out[i]='1';
			else out[i]='0';
		}
		printf("Case #%d: ",++cas);
		puts(out);
	}
	return 0;
}

