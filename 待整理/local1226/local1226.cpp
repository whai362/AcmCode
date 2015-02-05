#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int main(){
	int i,flag=0;
	char str[1010];
	stack<char> s;
	while(scanf("%s",str)!=EOF){
		for(i=0;i<strlen(str);++i){
			if(s.empty()) s.push(str[i]);
			else if(str[i]==')'&&s.top()=='('||str[i]==']'&&s.top()=='['||str[i]=='}'&&s.top()=='{') s.pop();
			else s.push(str[i]);
		}
		if(s.empty()) printf("Yes\n");
		else{
			printf("No\n");
			while(!s.empty()) s.pop();
		}
	}
	return 0;
}
