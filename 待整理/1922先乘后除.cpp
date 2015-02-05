#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,t,v;
	double ans;
	while(scanf("%d",&n) && n){
		ans=10e9;
		while(n--){
			scanf("%d%d",&v,&t);
			if(t>=0) ans=min(ans,(4500.0*3.6/v+t));
		}
		if(ans>(int)ans) printf("%d\n",(int)ans+1);
		else printf("%d\n",(int)ans);
	}
	return 0;
}
