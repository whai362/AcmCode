#include<cstdio>
#include<iostream>
using namespace std;
__int64 n,k,d1,d2;
int gao(__int64 x2,int fc){
	__int64 x1,x3;
	if(x2>=0){
		switch(fc){
			case 0:
				x1=x2+d1;
				x3=x2-d2;
				if(x1>=0 && x3>=0){
					if(x1<=n/3 && x2<=n/3 && x3<=n/3)
						return 1;
					else return 0;
				}
				else return 0;
			case 1:
				x1=x2+d1;
				x3=x2+d2;
				if(x1>=0 && x3>=0){
					if(x1<=n/3 && x2<=n/3 && x3<=n/3)
						return 1;
					else return 0;
				}
				else return 0;
			case 2:
				x1=x2-d1;
				x3=x2-d2;
				if(x1>=0 && x3>=0){
					if(x1<=n/3 && x2<=n/3 && x3<=n/3)
						return 1;
					else return 0;
				}
				else return 0;
			case 3:
				x1=x2-d1;
				x3=x2+d2;
				if(x1>=0 && x3>=0){
					if(x1<=n/3 && x2<=n/3 && x3<=n/3)
						return 1;
					else return 0;
				}
				else return 0;
		}
	}
	return 0;
}
int main(){
	int T;
	__int64 tmp,x2[4];
	scanf("%d",&T);
	while(T--){
		cin>>n>>k>>d1>>d2;
		if(n%3==0){
			tmp=k-d1+d2;
			if(tmp%3==0) x2[0]=tmp/3;
			else x2[0]=-1;
			tmp=k-d1-d2;
			if(tmp%3==0) x2[1]=tmp/3;
			else x2[1]=-1;
			tmp=k+d1+d2;
			if(tmp%3==0) x2[2]=tmp/3;
			else x2[2]=-1;
			tmp=k+d1-d2;
			if(tmp%3==0) x2[3]=tmp/3;
			else x2[3]=-1;
			int flag=0;
			for(int i=0;i<4;++i){
				if(gao(x2[i],i)){
					flag=1;
					break;
				}
			}
			if(flag) printf("yes\n");
			else printf("no\n");
		}
		else printf("no\n");
	}
	return 0;
}
