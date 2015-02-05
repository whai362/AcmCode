#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int i,n,tmp=0,d[100005];
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&d[i]);
		tmp+=d[i];
		cout<<tmp<<endl;
	}
	sort(d,d+n);
	if(d[0]==0 && tmp%3==0){
		for(i=n-1;i>=0;--i){
			printf("%d",d[i]);
		}
		printf("\n");
	}
	else printf("%d\n",-1);
	return 0;
}
