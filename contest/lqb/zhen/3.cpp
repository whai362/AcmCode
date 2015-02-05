#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 1000001
int main(){
	int a,b,c,cnt=0,i,j,k,l1,l2,l3,mid,n,hash[10];
	int low,high;
	char s1[10],s2[10],s3[10];
	scanf("%d",&n);
	if(n>=100000) printf("0\n");
	else{
	cnt=0;
	for(i=1;i<n;++i){
		a=i;
		low=1;
		high=100000;
		while(low+1<high){
			mid=(low+high)>>1;
			c=mid;
			b=c*(n-a);
			sprintf(s1,"%d",a);
			l1=strlen(s1);
			sprintf(s2,"%d",b);
			l2=strlen(s2);
			sprintf(s3,"%d",c);
			l3=strlen(s3);
			if(l1+l2+l3>9) high=mid;
			else if(l1+l2+l3<9) low=mid;
			else break;
		}
		for(j=mid;j>0;--j){
			int flag=0;
			c=j;
			b=c*(n-a);
			sprintf(s1,"%d",a);
			l1=strlen(s1);
			sprintf(s2,"%d",b);
			l2=strlen(s2);
			sprintf(s3,"%d",c);
			l3=strlen(s3);
			if(l1+l2+l3<9) break;
			memset(hash,0,sizeof(hash));
			for(k=0;k<l1;++k){
				if(!hash[s1[k]-'0']) hash[s1[k]-'0']=1;
				else{
					flag=1;
					break;
				}
			}
			if(!flag){
				for(k=0;k<l2;++k){
					if(!hash[s2[k]-'0']) hash[s2[k]-'0']=1;
					else{
						flag=1;
						break;
					}
				}
			}
			if(!flag){
				for(k=0;k<l3;++k){
					if(!hash[s3[k]-'0']) hash[s3[k]-'0']=1;
					else{
						flag=1;
						break;
					}
				}
			}
			if(!flag){
				for(k=1;k<10;++k){
					if(!hash[k]){
						flag=1;
						break;
					}
				}
				if(hash[0]==1) flag=1;
			}
			if(!flag) ++cnt;
		}
		for(j=mid+1;j<100000;++j){
			int flag=0;
			c=j;
			b=c*(n-a);
			sprintf(s1,"%d",a);
			l1=strlen(s1);
			sprintf(s2,"%d",b);
			l2=strlen(s2);
			sprintf(s3,"%d",c);
			l3=strlen(s3);
			if(l1+l2+l3>9) break;
			memset(hash,0,sizeof(hash));
			for(k=0;k<l1;++k){
				if(!hash[s1[k]-'0']) hash[s1[k]-'0']=1;
				else{
					flag=1;
					break;
				}
			}
			if(!flag){
				for(k=0;k<l2;++k){
					if(!hash[s2[k]-'0']) hash[s2[k]-'0']=1;
					else{
						flag=1;
						break;
					}
				}
			}
			if(!flag){
				for(k=0;k<l3;++k){
					if(!hash[s3[k]-'0']) hash[s3[k]-'0']=1;
					else{
						flag=1;
						break;
					}
				}
			}
			if(!flag){
				for(k=1;k<10;++k){
					if(!hash[k]){
						flag=1;
						break;
					}
				}
				if(hash[0]==1) flag=1;
			}
			if(!flag) ++cnt;
		}
	}
	printf("%d\n",cnt);
	}
	return 0;
}
