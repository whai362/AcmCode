#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2000005;
int a[N],b[N];
int q[N],h[N];
int un;
int n,m;
void gao(int u){
	int ans1,ans2;
	int lb=lower_bound(b+1,b+1+un,u)-b;
	//cout<<lb<<' '<<un<<endl;
	if(lb>un){
		ans1=n;
		ans2=0;
	}
	else if(lb==1){
		if(b[lb]==u){
			ans1=q[lb]-1;
			ans2=n-h[lb];
		}
		else{
			ans1=0;
			ans2=n;
		}
	}
	else if(b[lb]==u){
		ans1=q[lb]-1;
		ans2=n-h[lb];
	}
	else{
		ans1=q[lb]-1;
		ans2=n-h[lb-1];
	}
	printf("%d	%d\n",ans1,ans2);
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(q,-1,sizeof(q));
		memset(h,-1,sizeof(h));
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		un=unique(b+1,b+1+n)-(b+1);
		int pre=a[1];
		a[1]=1;
		q[1]=1;
		h[1]=1;
		for(int i=2;i<=n;++i){
			if(a[i]==pre) a[i]=a[i-1],h[a[i]]=i;
			else pre=a[i],a[i]=a[i-1]+1,q[a[i]]=i,h[a[i]]=i;
		}
		int u;
		for(int i=0;i<m;++i){
			scanf("%d",&u);
			gao(u);
		}
	}
	return 0;
}
