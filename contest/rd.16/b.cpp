#include<cstdio>
using namespace std;
int main(){
	int ans=300,i,j,k,n,s,tmp;
	scanf("%d%d",&n,&s);
	for(i=0;i<=s/5;++i)
	  for(j=0;j<=(s-5*i)/4;++j)
		for(k=0;k<=(s-5*i-4*j)/3;++k){
			if(!((s-5*i-4*j-3*k)%2)){
				tmp=(s-5*i-4*j-3*k)/2;
				if((i+j+k+tmp)==n)
				  if(tmp<ans) ans=tmp;
			}
		}
	printf("%d\n",ans);
	return 0;
}
