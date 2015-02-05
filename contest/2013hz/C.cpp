#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define Maxn 100050
#define lson l, mid ,rt<<<1
#define rson mid+1, r ,rt<<1|1`
#define LL __int64


LL sum[4][Maxn<<2];

int main(){
	
	while (~scanf("%d%d",&n,&m)){
		if (n==0&&m==0) break;
		Build(1,n,1);
		for (int i=1;i<=m;i++){
			scanf("%d%d%d%d",&p,&x,&y,&z);
			if (p==1){
				update1(x,y,z,1,n,1);
			}
			else if(p==2){
				update2(x,y,z,1,n,1);
			}
			else if(p==3){
				update3(x,y,z,1,n,1);
			}
			else {
				printf("%d")
			}
		}
	}
	
	return 0;
}
