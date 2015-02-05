#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[205],g[205],str[205];
int main(){
	int l,len,T,flag;
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		memset(s,0,sizeof(s));
		len=strlen(str);
		l=0;
		for(int i=0;i<len;++i){
			if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
				s[l++]=str[i];
			}
		}
		//cout<<s<<endl;
		char t1[205],t2[205],t3[205];
		flag=0;
		for(int i=1;i<=l/3;++i){
			for(int j=1;j<=l/2;++j){
				if(3*i+2*j>l) break;
				else{
					memset(t1,0,sizeof(t1));
					memset(t2,0,sizeof(t2));
					for(int k=0;k<i;++k)
						t1[k]=s[k];
					for(int k=i;k<i+j;++k)
						t2[k-i]=s[k];
					int ll1=strlen(t1),
						ll2=strlen(t2);
					memset(g,0,sizeof(g));
					if(t1 && t2 && strcmp(t1,t2)){
						strcat(g,t1);
						strcat(g,t2);
						strcat(g,t1);
						strcat(g,t2);
						strcat(g,t1);
					}
					if(strcmp(g,s)==0)
						flag=1;
				}
			}
		}

		for(int i=1;i<=l/3;++i){
			for(int j=1;j<=l/2;++j){
				for(int k=1;k<=l;++k){
					if(3*i+3*j+k>l) break;
					else{
						memset(t1,0,sizeof(t1));
						memset(t2,0,sizeof(t2));
						memset(t3,0,sizeof(t3));
						for(int u=0;u<i;++u)
							t1[u]=s[u];
						for(int u=i;u<i+j;++u)
							t2[u-i]=s[u];
						for(int u=2*(i+j);u<2*(i+j)+k;++u)
							t3[u-2*(i+j)]=s[u];
						int ll1=strlen(t1),
							ll2=strlen(t2),
							ll3=strlen(t3);
						memset(g,0,sizeof(g));
						if(ll1 && ll2 && ll3 && strcmp(t1,t2) && strcmp(t1,t3) && strcmp(t2,t3)){
							strcat(g,t1);
							strcat(g,t2);
							strcat(g,t1);
							strcat(g,t2);
							strcat(g,t3);
							strcat(g,t1);
							strcat(g,t2);
						}
						if(strcmp(g,s)==0)
							flag=1;
					}
				}
			}
		}
		if(flag==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
