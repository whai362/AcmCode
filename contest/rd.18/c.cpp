#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
#define N 100005
int main(){
	bool hash[30];
	char max,str[N];
	int i,last[30];
	stack<char> s;
	scanf("%s",str);
	memset(hash,0,sizeof(hash));
	memset(last,0,sizeof(last));
	int len=strlen(str);
	for(i=0;i<len;++i){
		if(!hash[str[i]-'a']) hash[str[i]-'a']=1,last[str[i]-'a']=i;
		else last[str[i]-'a']=i;
	}
	for(i=0;i<27;++i)
	  if(hash[i]) s.push(i+'a');
	i=0;
	while(!s.empty()){
	  max=s.top();
	  s.pop();
	  for(;i<=last[max-'a'];++i){
		  if(str[i]==max) printf("%c",max);
	  }
	}
	printf("\n");
	return 0;
}
