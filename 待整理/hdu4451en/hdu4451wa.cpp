#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
	int i,a,b,c1,p1,s1,n,sum=0,c[1010],p[1010],s[1010];
	char str1[10],str2[10];
	while(scanf("%d%d%d",&c1,&p1,&s1)&&(c1||p1||s1)){
	sum=0,memset(c,0,sizeof(c)),memset(p,0,sizeof(p)),memset(s,0,sizeof(s));
	scanf("%d",&n);
	while(n--){
		scanf("%s%d%s%d",str1,&a,str2,&b);
		if(str1[0]=='c'){
			if(c[a]&&p[b]) sum=sum+s1-1;
			else sum=sum+s1;
			c[a]=1,p[b]=1;
			for(i=0;i<s1;++i) s[i]=1;
		}
		else{
			if(c[a]&&p[b]) sum=sum+c1-1;
			else sum=sum+c1;
			p[a]=1,s[b]=1;
			for(i=0;i<c1;++i) c[i]=1;
		}
	}
	printf("%d\n",c1*p1*s1-sum);
	}
	return 0;
}
