#include<stdio.h>
#include<bitset>
using namespace std;
int main(){
	int n,x,y;
	char c;
	scanf("%x%c%d%c%d",&n,&c,&x,&c,&y);
	bitset<32>  b(n);
	b[x]=0,b[y]=b[y-1]=1,b[y-2]=0;
	printf("%x\n",b);
	return 0;
}
