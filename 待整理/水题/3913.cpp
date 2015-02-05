#include<cstdio>
using namespace std;
int main(){
	int a,b,c,n;
	scanf("%d",&n);
	printf("Gnomes:\n");
	while(n--){
		scanf("%d%d%d",&a,&b,&c);
		if((a<=b && b<=c) || (a>=b && b>=c)) printf("Ordered\n");
		else printf("Unordered\n");
	}
	return 0;
}
