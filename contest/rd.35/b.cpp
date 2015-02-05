#include<iostream>
#include<cstdio>
using namespace std;
int na,ma,nb,mb;
char a[55][55],b[55][55];
int bb(int i,int j){
	if(i<0 || i>=nb || j<0 || j>=mb) return 0;
	if(b[i][j]-'0') return 1;
	return 0;
}
int main(){
	int i,j,x,y,x0,y0,xx,yy,tmp,Max=0;
	scanf("%d%d",&na,&ma);
	for(i=0;i<na;++i){
		scanf("%s",a[i]);
	}
	scanf("%d%d",&nb,&mb);
	for(i=0;i<nb;++i){
		scanf("%s",b[i]);
	}
	x0=max(na,nb);
	y0=max(ma,mb);
	for(xx=-x0;xx<x0;++xx)
	  for(yy=-y0;yy<y0;++yy){
		  tmp=0;
		  for(i=0;i<na;++i){
			  for(j=0;j<ma;++j){
				  tmp+=(a[i][j]-'0')*bb(i+xx,j+yy);
			  }
		  }
		  if(tmp>Max) Max=tmp,x=xx,y=yy;
	  }
	printf("%d %d\n",x,y);
	return 0;
}
