#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const LL INF=(LL)0x3f3f3f3f*0x3f3f3f3f;
int n,m,A,B;
int ax[105],ay[105],bx[105],by[105];
LL sqr(int x){
	return (LL)x*x;
}
LL _abs(int x){
	if(x<0) return (LL)(-x);
	return (LL)x;
}
LL deal(int x,int y){
	LL ret=0;
	for(int i=0;i<A;++i){
		ret+=sqr(ax[i]-x)+sqr(ay[i]-y);
	}
	LL _min=INF;
	for(int i=0;i<B;++i){
		_min=min(_min,_abs(bx[i]-x)+_abs(by[i]-y));
	}
	ret+=_min;
	return ret;
}
void gao(){
	LL ans=INF;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			//cout<<deal(i,j)<<' ';
			ans=min(ans,deal(i,j));
		}
		//cout<<endl;
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		scanf("%d%d%d%d",&n,&m,&A,&B);
		for(int i=0;i<A;++i){
			scanf("%d%d",&ax[i],&ay[i]);
		}
		for(int i=0;i<B;++i){
			scanf("%d%d",&bx[i],&by[i]);
		}
		printf("Case #%d: ",++cas);
		gao();
	}
	return 0;
}
