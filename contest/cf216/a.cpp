#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct circle{
	int x;
	int d;
}c[1005];
int main(){
	int i,j,flag,n,a[1005];
	scanf("%d",&n);
	flag=0;
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;++i){
	  c[i].x=min(a[i],a[i+1]);
	  c[i].d=abs(a[i+1]-a[i]);
	}
	for(i=0;i<n-2;++i){
	  for(j=i+1;j<n-1;++j){
		  if(c[i].x<c[j].x){
			  if((c[j].x-c[i].x<c[i].d) && (c[i].x+c[i].d<c[j].x+c[j].d)){
				  flag=1;
				  break;
			  }
		  }
		  else if(c[i].x>c[j].x){
			  if((c[i].x-c[j].x<c[j].d) && (c[j].x+c[j].d<c[i].x+c[i].d)){
				  flag=1;
				  break;
			  }
		  }
	  }
	  if(flag) break;
	}
	if(!flag) printf("no\n");
	else printf("yes\n");
	return 0;
}
