#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
struct Data{
	int a,b;
	Data(){}
	Data(int _a,int _b){
		a=_a;
		b=_b;
	}
}ans[100000];
int cnt=0;
int main(){
	
	for(int i=100;i<1000;++i){
		for(int j=i+1;j<1000;++j){
			if(i+j<1000){
				int sum=i+j;
				int hash[10];
				memset(hash,0,sizeof(hash));
				char num1[5],num2[5],num3[5];
				sprintf(num1,"%d",i);
				sprintf(num2,"%d",j);
				sprintf(num3,"%d",sum);
				int len=strlen(num1);
				for(int k=0;k<len;++k){
					++hash[num1[k]-'0'];
				}
				len=strlen(num2);
				for(int k=0;k<len;++k){
					++hash[num2[k]-'0'];
				}
				len=strlen(num3);
				for(int k=0;k<len;++k){
					++hash[num3[k]-'0'];
				}
				int flag=1;
				for(int k=0;k<10;++k){
					if(hash[0]>0 || hash[k]>1) flag=0;
				}
				if(flag){
					ans[cnt++]=Data(i,j);
				}
			}
		}
	}
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		--n;
		printf("%d + %d = %d\n",ans[n].a,ans[n].b,ans[n].a+ans[n].b);
	}
	/*for(int i=0;i<cnt;++i){
		cout<<ans[i].a<<" "<<ans[i].b<<endl;
	}*/
	return 0;
}
