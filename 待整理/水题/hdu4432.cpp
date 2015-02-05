#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int a[100000000];
char b[100000000];

void itoa(char bnum[],int num,int jz){
	int i,count=0,n[500];
	while(num) n[count]=num%jz,++count,num=num/jz;
	for(i=0;i<count;++i){
		bnum[i]=n[count-1-i]+48;
		if(n[count-1-i]>9) bnum[i]='A'+n[count-1-i]-10;
	}
	bnum[count]=0;
}

int div(int n,int a[]){
	int i,count=0;
	for(i=1;i*i<=n;++i){
		if(n%i==0){
		  a[count++]=i;
		  if(n/i!=i) a[count++]=n/i;
		}
	}
	return count;
}
int main(){
	int i,j,m,n,count,sum,tmp;
	while(scanf("%d%d",&n,&m)!=EOF){
	sum=0;
	count=div(n,a);
	for(i=0;i<count;++i){
		itoa(b,a[i],m);
		//cout<<b<<endl;
		for(j=0;j<strlen(b);++j){
			if(b[j]<'0'||b[j]>'9') tmp=b[j]-'A'+10;
			else tmp=b[j]-48;
			//cout<<tmp<<endl;
			sum=sum+tmp*tmp;
		}
			 
	}
	itoa(b,sum,m);
	printf("%s\n",b);
	}
	return 0;
}
