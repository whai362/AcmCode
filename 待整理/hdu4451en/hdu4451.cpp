#include<stdio.h>
#include<string.h>
int imf[1010][2];
int main(){
	int i,a,b,c,p,s,n,sum=0;
	char str1[10],str2[10];
	while(scanf("%d%d%d",&c,&p,&s)&&(c||p||s)){
		sum=0;
		memset(imf,0,sizeof(imf));
		scanf("%d",&n);
		while(n--){
			scanf("%s%d%s%d",str1,&a,str2,&b);
			if(str1[0]=='c') ++imf[b][0];
			else ++imf[a][1];
		}
		for(i=1;i<=p;++i){
			sum=sum+imf[i][0]*s+imf[i][1]*c-imf[i][0]*imf[i][1];
		}
		printf("%d\n",c*p*s-sum);
	}
	return 0;
}
