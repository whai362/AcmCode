#include<cstdio>
using namespace std;
int a[4][4],t[3];
int main(){
	int i,j,mi,_max=0,tmp=0;
	for(i=0;i<3;++i)
	  for(j=0;j<3;++j){
		  scanf("%d",&a[i][j]);
		  t[i]+=a[i][j];
	  }
	for(i=0;i<3;++i){
		if(t[i]>_max) _max=t[i],mi=i;
	}
	a[mi][mi]=1;
	for(i=0;i<3;++i){
		if(i!=mi) a[i][i]=t[mi]-t[i]+1,tmp+=a[i][i];
	}
	tmp=(t[mi]-tmp)/2;
	for(i=0;i<3;++i)
	  a[i][i]+=tmp;
	for(i=0;i<3;++i){
		printf("%d",a[i][0]);
		for(j=1;j<3;++j){
			printf(" %d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
