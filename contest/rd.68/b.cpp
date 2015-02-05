#include<cstdio>
using namespace std;
int ti[100005];
int main(){
	int c,i,j,n,m,s=0,t,v;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		scanf("%d%d",&c,&t);
		s+=c*t;
		ti[i+1]=s;
	}
	j=1;
	for(i=0;i<m;++i){
		scanf("%d",&v);
		for(;j<=n;++j){
			if(v<=ti[j]) break;
		}
		printf("%d\n",j);
	}
	return 0;
}
