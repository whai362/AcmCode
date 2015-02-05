#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int i,n;
	double left,right;
	while(scanf("%d",&n) && n){
		n=(n-1960)/10+2;
		left=pow(2.0,n+0.0)*log(2.0);
		i=0,right=0.0;
		while(left>=right){
			++i;
			right+=log(i+0.0);
		}
		printf("%d\n",i-1);
	}
	return 0;
}
