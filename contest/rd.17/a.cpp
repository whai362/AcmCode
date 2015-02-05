#include<cstdio>
using namespace std;
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	c=c*(a-b);
	if(c%b) printf("%d\n",c/b+1);
	else printf("%d\n",c/b);
	return 0;
}
