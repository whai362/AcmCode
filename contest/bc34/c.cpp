#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=50005;
const LL INF=100000000000LL;
LL a[3*N],hh[3*N];
int n;
LL w,h;
void predo(){
	int p=0,q=0;
	LL s=0;
	while(q<2*w+n){
		while(q-p+1<=w){
			s+=a[q];
			++q;
		}
		LL th=s/w;
		if(s-w*th<w*(th+1)-s) ++th;
		hh[p]=max(h,th);
		s-=a[p];
		++p;
	}
}
int main(){
	while(scanf("%d%I64d%I64d",&n,&w,&h)!=EOF){
		memset(a,0,sizeof(a));
		LL sum=0;
		for(int i=0;i<n;++i){
			scanf("%I64d",&a[i+w]);
			sum+=a[i+w];
		}
		if(sum<w*h){ puts("-1"); continue; }
		predo();
		int p=0,q=0;
		LL xy=0,nb=0;
		LL ans=INF;
		while(q<2*w+n){
			while(q-p+1<=w){
				if(a[q]>h[p]) nb+=a[q]-h[p];
				else xy+=h[p]-a[q];
				++q;
			}
			cout<<xy<<' '<<nb<<endl;
			//if(xy<nb) ans=min(ans,nb);
			//else ans=min(ans,xy);
			if(a[p]>h[p]) nb-=a[p]-h[p];
			else xy-=h[p]-a[p];
			++p;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
