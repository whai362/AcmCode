#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1000005
int cnt,cntr,r[N],a[N],b[N];
bool cmp1(int a,int b){
	return a<b;
}
bool cmp2(int a,int b){
	return a>b;
}
int main(){
	char op[2];
	int i,n,num,t,p;
	while(scanf("%d%d",&t,&n)!=EOF){
		cnt=cntr=0;
		p=1;
		for(i=0;i<n;++i){
			scanf("%d",&r[i]);
		}
		while(1){
			scanf("%s",op);
			if(op[0]=='a'){
				scanf("%d",&num);
				a[cnt++]=num;
			}
			else if(op[0]=='p'){
				scanf("%d",&num);
				p=num;
			}
			else if(op[0]=='r'){
				if(p==1){
					sort(a,a+cnt,cmp2);
					b[cntr++]=a[--cnt];
				}
				else{
					sort(a,a+cnt,cmp1);
					b[cntr++]=a[--cnt];
				}
			}
			else break;
		}
		for(i=0;i<n;++i){
			if(r[i]>cntr) printf("-1\n");
			else printf("%d\n",b[r[i]-1]);
		}
		printf("\n");
	}
	return 0;
}
