#include<stdio.h>
#include<stack>
using namespace std;
int mod[600000];
int main(){
	int i,n;
	stack<int> ans;
	while(scanf("%d",&n)&&n){
		mod[1]=1%n;
		for(i=2;mod[i-1]!=0;++i) mod[i]=(mod[i/2]*10+i%2)%n;	//宽搜，正好枚举每一位为0或1的情况
		--i;
		while(i>=1) ans.push(i%2),i=i/2;
		while(!ans.empty()) printf("%d",ans.top()),ans.pop();
		printf("\n");
	}
	return 0;
}
