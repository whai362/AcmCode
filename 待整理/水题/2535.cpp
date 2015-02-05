#include<stdio.h>
int n,m,max,min,a[105],p[105];
void get_max_min(int a[]){
	for(int i=0;i<m;++i){
		if(a[i]>max) max=a[i];
		if(a[i]<min) min=a[i];
	}
}
int main(){
	int i,j,f=1,half;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
	  for(j=0;j<m;++j) scanf("%d",&a[j]);
	  max=-1,min=1001;
	  get_max_min(a);
	  for(j=0;j<m;++j){
		  if(a[j]==max) p[j]=-1;
		  if(a[j]==min&&p[j]!=-1) ++p[j];
	  }
	}
	if(n%2==0) half=n/2;
	else half=n/2+1;
	for(i=0;i<m;++i){
		if(p[i]>=half) f=0,printf("%d ",i+1);
	}
	if(f) printf("0");
	printf("\n");
	return 0;
}
