#include<cstdio>
#include<cstring>
using namespace std;
#define N 100005
int main(){
	int count=0,i,j,m,min=0,n,tmp;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
		if(!((m+1)%2)){
			tmp=(m+1)/2;
			for(j=0;j<n/m;++j)
			for(i=tmp;i>0;--i){
				printf("%d\n",i);
				printf("%d\n",2*tmp-i);
			}
			if(n%2){
			for(i=tmp;i>0;--i){
				printf("%d\n",i);
				printf("%d\n",2*tmp-i);
			}
			}
		}
		else{
			tmp=m/2;
			for(i=tmp;i>0;--i){
					printf("%d\n",i);
					printf("%d\n",2*tmp+1-i);
			}
		}
	}
	return 0;
}
