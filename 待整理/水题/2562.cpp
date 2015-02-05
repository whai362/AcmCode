#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int main(){
	char num1[15],num2[15];
	int count,flag,i,tmp1,tmp2;
	stack<int> s1;
	stack<int> s2;
	while(scanf("%s%s",num1,num2)){
		if(strlen(num1)==1&&strlen(num2)==1&&num1[0]=='0'&&num2[0]=='0') break;
		for(i=0;i<strlen(num1);++i) s1.push(num1[i]-'0');
		for(i=0;i<strlen(num2);++i) s2.push(num2[i]-'0');
		count=0,flag=0;
		while(!s1.empty()||!s2.empty()){
			if(!s1.empty()) tmp1=s1.top(),s1.pop();
			else tmp1=0;
			if(!s2.empty()) tmp2=s2.top(),s2.pop();
			else tmp2=0;
			if(tmp1+tmp2+flag>=10) flag=1,++count;
			else flag=0;
		}
		if(count>1) printf("%d carry operations.\n",count);
		else if(count==1)printf("1 carry operation.\n");
		else printf("No carry operation.\n");
	}
	return 0;
}
