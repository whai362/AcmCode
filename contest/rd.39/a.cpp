#include<cstdio>
using namespace std;
int t[25][60];
int main(){
	int cnt=0,n,h,m;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&h,&m);
		++t[h][m];
		if(t[h][m]>cnt) cnt=t[h][m];
	}
	printf("%d\n",cnt);
	return 0;
}
