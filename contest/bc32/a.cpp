#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct Dt{
	int a;
	int b;
	int i;
}d[105];
bool cmp(Dt a,Dt b){
	if(a.a==b.a && a.b==b.b) return a.i<b.i;
	else if(a.a==b.a) return a.b<b.b;
	else return a.a<b.a;
		
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int a,b;
		for(int i=0;i<n;++i){
			scanf("%d%d",&a,&b);
			d[i].a=b-a;
			d[i].b=b;
			d[i].i=i;
		}
		sort(d,d+n,cmp);
		for(int i=0;i<n;++i){
			printf("%d%c",d[i].i,i==n-1?'\n':' ');
		}
	}

	return 0;
}
