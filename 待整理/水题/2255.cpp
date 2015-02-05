#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int main(){
	int i,level[30];
	char str1[50],str2[50];
	stack<char> s;
	while(scanf("%s%s",str1,str2)!=EOF){
	for(i=0;i<strlen(str1);++i)	level[str1[i]%26]=i;
	for(i=0;i<strlen(str2);++i){
		if(str2[i]!=str1[0]){
			if(s.empty()||level[str2[i]%26]>level[s.top()%26]) s.push(str2[i]);
			else{
				while(!s.empty()&&level[str2[i]%26]<level[s.top()%26]){
					printf("%c",s.top());
					s.pop();
				}
				s.push(str2[i]);
			}
		}
		else{
			while(!s.empty()){
				printf("%c",s.top());
				s.pop();
			}
		}
	}
	while(!s.empty()){
		printf("%c",s.top());
		s.pop();
	}
	printf("%c\n",str1[0]);
	}
	return 0;
}

