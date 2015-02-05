#include<cstdio>
using namespace std;
int main(){
	int i,j,n,t;
	char tmp,q[55];
	scanf("%d%d%s",&n,&t,q);
	for(i=0;i<t;++i)
	    for(j=0;j<n-1;++j){
			if(q[j]=='B' && q[j+1]=='G'){
				tmp=q[j];
				q[j]=q[j+1];
				q[j+1]=tmp;
				++j;
			}
		}
	printf("%s\n",q);
	return 0;
}
