#include<stdio.h>
#include<string.h>
int mul(int a[],int b[],int ans[],int an,int bn){
    int i,j,ansn;
    ansn=an+bn-1;
    for(i=0;i<an;++i)
	  for(j=0;j<bn;++j){
        ans[i+j]=a[i]*b[j]+ans[i+j];
        ans[i+j+1]=ans[i+j]/10+ans[i+j+1];
        ans[i+j]=ans[i+j]%10;
      }
    while(!ans[ansn]) ansn--;
	return ansn;
}
int main(){
	int an,bn,ansn,i,j,k;
	int a[100],b[100],ans[100],n[120];
	char num[100],tmp[5];
	while(scanf("%s",num)!=EOF){
		an=strlen(num);
		for(i=an-1;i>=0;--i) a[an-1-i]=num[i]-48;
		for(i=0;i<2*an;++i) n[2*an-1-i]=num[i%an]-48;
		for(i=1;i<=an;++i){
			sprintf(tmp,"%d",i);
			bn=strlen(tmp);
			for(j=bn-1;j>=0;--j) b[bn-1-j]=tmp[j]-48;
			memset(ans,0,sizeof(ans));
			ansn=mul(a,b,ans,an,bn);
			for(j=0;j<an;++j){
				for(k=0;k<=ansn;++k){
					if(n[j+k]!=ans[k]) break;
				}
				if(k>ansn) break;
			}
			if(j==an) break;
		}
		if(i>an) printf("%s is cyclic\n",num);
		else printf("%s is not cyclic\n",num);
	}
	return 0;
}

