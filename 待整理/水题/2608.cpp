#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int trans(char c){
	if(c=='B'||c=='F'||c=='P'||c=='V') return 1;
	if(c=='C'||c=='G'||c=='J'||c=='K'||c=='Q'||c=='S'||c=='X'||c=='Z') return 2;
	if(c=='D'||c=='T') return 3;
	if(c=='L') return 4;
	if(c=='M'||c=='N') return 5;
	if(c=='R') return 6;
	return 0;
}

int main(){
	int i,tmp;
	char str[50];
	queue<int> q;
	while(scanf("%s",str)!=EOF){
		for(i=0;i<strlen(str);++i){
			tmp=trans(str[i]);
			if(q.empty()||tmp!=q.back()) q.push(tmp);
		}
		while(!q.empty()){
			if(q.front()) printf("%d",q.front());
		    q.pop();
		}
		printf("\n");
	}
	return 0;
}

