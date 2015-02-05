#include<cstdio>
#include<cmath>
using namespace std;
int a[6][6];
int main(){
	int i,j,x,y,tmp;
	for(i=0;i<5;++i){
		for(j=0;j<5;++j){
			scanf("%d",&a[i][j]);
			if(a[i][j]) x=i,y=j;
		}
	}
	tmp=abs(x-2)+abs(y-2);
	printf("%d\n",tmp);
	return 0;
}
