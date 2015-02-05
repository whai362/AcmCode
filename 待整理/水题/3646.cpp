#include<stdio.h>
#include<algorithm>
using namespace std;
int h[20005],c[20005];
int main(){
	int i,j,n,m,sum;
	while(scanf("%d%d",&n,&m)&&(n||m)){
		sum=0;
		for(i=0;i<n;++i) scanf("%d",&h[i]);
		for(i=0;i<m;++i) scanf("%d",&c[i]);
		if(n>m) printf("Loowater is doomed!\n");
		else{
			i=0,j=0;
			sort(h,h+n);
			sort(c,c+m);
			while(i<n&&j<m){
				if(h[i]<=c[j]) sum=sum+c[j],++i,++j;
				else ++j;
			}
			if(i==n) printf("%d\n",sum);
			else printf("Loowater is doomed!\n");
		}
	}
	return 0;
}
