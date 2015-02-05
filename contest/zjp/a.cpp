#include<cstdio>
using namespace std;
int main(){
	int a,t,m,n,s1,s2;
	int i;
	scanf("%d",&t);
	while(t--){
	scanf("%d%d",&n,&m);
	s1=0,s2=0;
	for(i=0;i<n;++i){
		scanf("%d",&a);
		s1+=a;
	}
	for(i=0;i<m;++i){
		scanf("%d",&a);
		s2+=a;
	}
	if(s1>s2)
		printf("Calem\n");
	else if(s1<s2)
	  printf("Serena\n");
	else printf("Draw\n");
	}
	return 0;
}
