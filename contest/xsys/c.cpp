#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
	n%=9;
	m%=9;
	if(!n) n=9;
	if(!m) m=9;
	if(n%2==0 && m%2==0) printf("Pixis\n");
	else printf("Armin\n");
	}
	return 0;

}
