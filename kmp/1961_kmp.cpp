#include<cstdio>
#include<iostream>
using namespace std;
const int N=1e6+5;
int n;
char str[N];
int next[N];
void getNext(){
	int i,j;
	i=0;
	j=next[0]=-1;
	while(i<n){
		if(j==-1 || str[i]==str[j])
			next[++i]=++j;
		else
			j=next[j];
	}
}
int main(){
	int cas=0;
	while(scanf("%d",&n) && n){
		scanf("%s",str);
		getNext();
		printf("Test case #%d\n",++cas);
		for(int i=1;i<=n;++i){
			int pri=i-next[i];
			if(i!=pri && i%pri==0)
				printf("%d %d\n",i,i/pri);
		}
		puts("");
	}
	return 0;
}
