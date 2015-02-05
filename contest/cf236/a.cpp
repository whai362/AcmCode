#include<cstdio>
using namespace std;
int main(){
	int k,a,b,v;
	int ans,t1,t2,t3;
	scanf("%d%d%d%d",&k,&a,&b,&v);
	t1=b/(k-1)*k;
	t2=b%(k-1)+1;
	t3=a/v;
	if(a%v!=0) ++t3;
	if(t3<=t1) ans=t1/k;
	else if(t3<=t1+t2) ans=t1/k+1;
	else ans=t1/k+1+(t3-t1-t2);
	printf("%d\n",ans);
	return 0;
}
#include<cstdio>
using namespace std;
int main(){
	int k,a,b,v;
	while(scanf("%d%d%d%d",&k,&a,&b,&v)!=EOF){
		int ans=0;
		while(a>0){
			if(k<=b){
				a=a-k*v;
				ans++;
				b=b-(k-1);
				continue;
			}
			if(k>b){
				a=a-v*(b+1);
				b=0;
				ans++;
				continue;
			}
			a=a-v;
			ans++;
		}
	 printf("%d\n",ans);
	}
	return 0;
}

