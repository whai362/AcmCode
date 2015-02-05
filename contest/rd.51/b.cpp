#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int ans=0,i,h1,h2,n;
	scanf("%d",&n);
	h1=0;
	for(i=0;i<n;++i){
		scanf("%d",&h2);
		if(i==0) ans+=h2+1;
		else if(h2>=h1) ans+=h2-h1+2;
		else ans+=(h1-h2)+2;
		h1=h2;
	}
	printf("%d\n",ans);
	return 0;
}
