#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,x,y,tmp;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		x=-1;
		tmp=(int)sqrt(n);
		if(tmp*tmp==n) --tmp;
		int _min=0x3f3f3f3f;
		for(int i=tmp;i>0;--i){
			//cout<<i<<endl;
			if(n%i==0){
				int tmp1=n/i-i;
				//cout<<i<<' '<<tmp1<<endl;
				if(tmp1%2==0){
					x=tmp1/2;
					_min=min(x,_min);
				}
			}
		}
		if(_min!=0x3f3f3f3f)
			printf("%d\n",_min);
		else
			printf("-1\n");
	}
	return 0;
}
