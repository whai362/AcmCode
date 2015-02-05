#include<stdio.h>
int main(){
	int n,a,b,x,y;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		if((a+b)%2==0){
			x=(a+b)/2;
			y=a-x;
			if(y>=0) printf("%d %d\n",x,y);
			else printf("impossible\n");
		}
		else printf("impossible\n");
	}
	return 0;
}
