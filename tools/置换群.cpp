/*
   题意：给你一个数字序列（每个数字唯一），每次你可以交换任意两个数字，代价为这两个数字的和，问最少用多少代价能把这个序列按升序排列好。
*/
#include<stdio.h>
#include<algorithm>
#define M 0x3f3f3f3f
using namespace std;
int cow[100010],sorted[100010],hash[100010],visited[100010];
int main(){
	int begin,i,len,n,submin,sum,tmp1,tmp2,ans=0,min=M;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&cow[i]);
		if(cow[i]<min) min=cow[i];
		sorted[i]=cow[i];
		hash[cow[i]]=i;
	}
	sort(sorted,sorted+n);
	while(n){
		i=0,sum=0,len=0,submin=M;
		while(visited[i]) ++i;
		begin=i;
		while(1){
			--n;
			++len;
			visited[i]=1;
			sum=sum+cow[i];
			if(cow[i]<submin) submin=cow[i];
			i=hash[sorted[i]];
			if(i==begin) break;	
		}
		if(len==1) continue;
		tmp1=(len-2)*submin;
		tmp2=submin+(len+1)*min;	//1+len-1+1
		ans=ans+(tmp1<tmp2? tmp1:tmp2);
		ans=ans+sum;
	}
	printf("%d",ans);
	return 0;
}

