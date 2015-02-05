/*
求出多边形最窄的地段长度
枚举边，求出所有点中到边的距离最大的值
这些值中最小的就是答案
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
const int MAXN = 109;
const double eps = 1e-4;
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{
    double x,y;
}p[MAXN],h[MAXN];

inline double distance(const point &p1,const point &p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
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
	for(p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
	if(p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
	p1=p[k=i];
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for(ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
	for(;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}

int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
	point* temp=new point[n];
	int s,i;
	_graham(n,p,s,temp);
	for(convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
	if(maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
	convex[n++]=temp[i];
	delete []temp;
	return n;
}

double judge(point _x,point _y,int len)
{
    double res=0;
    for(int i=0;i<len;i++)
    {
        double tmp=fabs(xmult(h[i],_x,_y))/distance(_x,_y);
        if(tmp>res)
        res=tmp;
    }
    return res;
}
double solve(int len)
{
    h[len]=h[0];
    double ans=1<<30;
    for(int i=0;i<len;i++)
    {
        double tmp=judge(h[i],h[i+1],len);//枚举边
        if(tmp<ans)
        ans=tmp;
    }
    return ans;
}
int main(){
    int n,len;
    int d=0;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
		len=graham(n,p,h);
        //Graham_scan(p,h,n,len);
        printf("Case %d: %.2lf\n",++d,solve(len)+0.005);
    }
    return 0;
}
