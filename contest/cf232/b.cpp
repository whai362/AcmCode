#include<cstdio>
using namespace std;
int main(){
	int l,r,n,t,tmp1,tmp2;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&l,&r);
		if(n<l) printf("No\n");
		else{
			tmp1=n/l;
			tmp2=n%l;
			if(!tmp2) printf("Yes\n");
			else if(!(tmp2%tmp1)){
				if(l+tmp2/tmp1<=r) printf("Yes\n");
				else printf("No\n");
			}
			else{
				if(l+tmp2/tmp1+1<=r) printf("Yes\n");
				else printf("No\n");
			}
		}
	}
	return 0;
}
