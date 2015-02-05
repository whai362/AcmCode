#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[13];
int hash[7];
int main(){
	int b,cnt,i,j,k,l,f,n,a[7]={1,2,3,4,6,12};
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%s",s);
		cnt=0;
		memset(hash,0,sizeof(hash));
		for(j=0;j<6;++j){
			b=12/a[j];
			for(k=0;k<b;++k){
				f=1;
				for(l=k;l<12;l+=b){
					//cout<<l<<' '<<s[l]<<endl;
					if(s[l]!='X'){
						f=0;
						break;
					}
				}
				if(f==1){
					//cout<<"!: "<<a[j]<<endl;
					break;
				}
			}
			if(f==1) hash[j]=1,++cnt;
		}
		printf("%d ",cnt);
		for(j=0;j<6;++j){
			if(hash[j]) printf("%dx%d ",a[j],12/a[j]);
		}
		printf("\n");
	}
	return 0;
}
