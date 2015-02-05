#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cnt=0,a[3];
int main(){
	int i,j,k,n,tmp0=0,tmp1=0,tmp2=0;
	scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
	sort(a,a+3);
	for(i=n/a[0];i>=0;--i){
		tmp0=i*a[0];
		for(j=n/a[1];j>=0;--j){
			tmp1=tmp0+j*a[1];
			for(k=n/a[2];k>=0;--k){
				tmp2=tmp1+k*a[2];
				if(tmp2==n){
					cnt=i+j+k;
					break;
				}
				else if(tmp2<n) break;
			}
			if(cnt) break;
		}
		if(cnt) break;
	}
	printf("%d\n",cnt);
	return 0;
}
/*Input
53 10 11 23
Output
5
Answer
5
Checker Log
ok 5*/

