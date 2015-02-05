#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int i,j,n,t,t1,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		for(j=i;j<=n;++j){
			t=i*i+j*j;
			if(t>n*n) break;
			else{
				t1=(int)sqrt(t);
				if(t1*t1==t) ++cnt;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
