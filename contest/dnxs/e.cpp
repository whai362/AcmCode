#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
struct data{
	int a,id;
}d[105];
int main(){
	int ca;
	scanf("%d",&ca);
	while(ca--){
		int e,z,n;
		scanf("%d%d%d",&e,&z,&n);
		for(int i=0;i<n;i++)
		  scanf("%d",&d[i].a);
		if(z>n){
			if(e>=n+z) printf("Win\n");
			else printf("Draw\n");
		}
		else if(z==n){
			int _min=INF
			for(int i=0;i<n;++i){
				if(_min>d[i].a) _min=d[i].a;
			}
			e-=_min;
			if(e>=n+z-1) printf("Win\n");
			else printf("Draw\n");
		}
		
		}
	}
	return 0;
}

