#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("YES");
		puts("2 1");
		puts("1 2");
	}
	else if(n%2){
		puts("YES");
		int v,e;
		v=n+1;
		e=v*(v-1)/2-v/2+v-1;
		printf("%d %d\n",v*2+2,e*2+1);
		int cnt=0;
		for(int i=1;i<=v;++i){
			for(int j=i+1;j<=v;++j){
				if(i+v/2==j) continue;
				printf("%d %d\n",i,j);
				printf("%d %d\n",i+v,j+v);
				cnt+=2;
			}
		}
		int sp1=v*2+1;
		int sp2=v*2+2;
		for(int i=2;i<=v;++i){
			printf("%d %d\n",sp1,i);
			printf("%d %d\n",sp2,i+v);
			cnt+=2;
		}
		printf("%d %d\n",1,1+v);
		++cnt;
		//cout<<cnt<<endl;
	}
	else puts("NO");
	return 0;
}
