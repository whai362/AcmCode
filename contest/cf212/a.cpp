#include<cstdio>
#include<cstring>
using namespace std;
char a[10][10];
bool map1[10][10],map2[10][10];
int main(){
	int i,j,x1,y1,x2,y2,flag,t;
	for(i=1;i<=8;++i)
	  scanf("%s",a[i]+1);
	flag=0;
	memset(map1,0,sizeof(map1));
	memset(map2,0,sizeof(map2));
	for(i=1;i<=8;++i)
	  for(j=1;j<=8;++j){
		  if(a[i][j]=='K') x1=i,y1=j;
	  }
	for(i=x1;i<=8;i=i+4)
	  for(j=y1;j<=8;j=j+4)
		map1[i][j]=1;
	for(i=x1;i>=1;i=i-4)
	  for(j=y1;j<=8;j=j+4)
		map1[i][j]=1;
	for(i=x1;i<=8;i=i+4)
	  for(j=y1;j>=1;j=j-4)
		map1[i][j]=1;
	for(i=x1;i>=1;i=i-4)
	  for(j=y1;j>=1;j=j-4)
		map1[i][j]=1;
	for(i=1;i<=8;++i)
	  for(j=1;j<=8;++j){
		  if(a[i][j]=='#') map1[i][j]=0;
	  }
	for(i=1;i<=8;++i)
	  for(j=1;j<=8;++j){
		  if(a[i][j]=='K') x2=i,y2=j;
	  }
	for(i=x2;i<=8;i=i+4)
	  for(j=y2;j<=8;j=j+4)
		map2[i][j]=1;
	for(i=x2;i>=1;i=i-4)
	  for(j=y2;j<=8;j=j+4)
		map2[i][j]=1;
	for(i=x2;i<=8;i=i+4)
	  for(j=y2;j>=1;j=j-4)
		map2[i][j]=1;
	for(i=x2;i>=1;i=i-4)
	  for(j=y2;j>=1;j=j-4)
		map2[i][j]=1;
	for(i=1;i<=8;++i)
	  for(j=1;j<=8;++j){
		  if(a[i][j]=='#') map2[i][j]=0;
	  }
	for(i=1;i<=8;++i){
	  for(j=1;j<=8;++j){
		  if(map1[i][j] && map2[i][j]){
			  flag=1;
			  break;
		  }
	  }
	  if(flag) break;
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
