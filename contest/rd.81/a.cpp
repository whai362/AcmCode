#include<cstdio>
using namespace std;
int main(){
	int x,y,b;
	scanf("%d%d",&x,&y);
	if((x>0 && y>0) || (x<0 && y<0)){
		b=x+y;
		if(b>0)
		  printf("0 %d %d 0\n",b,b);
		else
		  printf("%d 0 0 %d\n",b,b);
	}
	else{
		b=y-x;
		if(b>0)
		  printf("%d 0 0 %d\n",-b,b);
		else
		  printf("0 %d %d 0\n",b,-b);
	}
	return 0;
}
