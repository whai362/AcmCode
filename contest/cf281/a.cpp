#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char na1[50],na2[50];
int h1[105],h2[105];
struct Data{
	int t;
	char s[5];
	int m;
	int c[5];
}d[100];
bool cmp(Data a,Data b){
	return a.t<b.t;
}
int main(){
	scanf("%s%s",na1,na2);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%s%d%s",&d[i].t,d[i].s,&d[i].m,d[i].c);
	}
	sort(d,d+n,cmp);
	for(int i=0;i<n;++i){
		if(d[i].c[0]=='y'){
			if(d[i].s[0]=='h'){
				if(h1[d[i].m]!=-1) ++h1[d[i].m];
				if(h1[d[i].m]==2){
					printf("%s %d %d\n",na1,d[i].m,d[i].t);
					h1[d[i].m]=-1;
				}
			}
			else{
				if(h2[d[i].m]!=-1) ++h2[d[i].m];
				if(h2[d[i].m]==2){
					printf("%s %d %d\n",na2,d[i].m,d[i].t);
					h2[d[i].m]=-1;
				}
			}
		}
		else{
			if(d[i].s[0]=='h'){
				if(h1[d[i].m]!=-1){
					printf("%s %d %d\n",na1,d[i].m,d[i].t);
					h1[d[i].m]=-1;
				}
			}
			else{
				if(h2[d[i].m]!=-1){
					printf("%s %d %d\n",na2,d[i].m,d[i].t);
					h2[d[i].m]=-1;
				}
			}
		}
	}
	return 0;
}
