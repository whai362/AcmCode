#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
long double f(int n){
	long double n1=(1+sqrt(5.0))/2,
		   n2=(1-sqrt(5.0))/2,
		   ret;
	//cout<<n1<<' '<<n2<<endl;
	ret=pow(n1,n)-pow(n2,n);
	return ret/sqrt(5);
}
struct Data{
	int flag,a,b;
}d[50];
int a[50];
int main(){
	int n;
	for(int i=1;i<=46;++i){
		a[i]=(int)f(i);
		//cout<<a[i]<<endl;
	}
	while(scanf("%d",&n) != EOF){
		for(int i=46;i>0;--i){
			if(n==1){
				puts("1");
				break;
			}
			else if(n==a[i]){
				printf("%d\n",i);
				break;
			}
			else if(n>a[i]){
				printf("%d %d\n",a[i],a[i+1]);
				break;
			}
		}
	}
	return 0;
}
