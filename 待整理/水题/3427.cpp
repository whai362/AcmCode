#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int ans=0,h,l,n;
    scanf("%d%d",&n,&l);
	while(n--){
		scanf("%d",&h);
		if(h%l==0) continue;
		ans=max(ans,l-h%l);
	}
	printf("%d\n",ans);
    return 0;
}

