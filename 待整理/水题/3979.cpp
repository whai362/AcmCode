#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int a,int b){
	if(b) return gcd(b,a%b);
	return a;
}
int main(){
	int a,b,c,d,tmp;
	char ch;
	while(scanf("%d%c%d%d%c%d",&a,&ch,&b,&c,&ch,&d)!=EOF){
		a=a*d+b*c,b=b*d,tmp=gcd(abs(a),b);
		if(a){
			if(b/tmp==1) printf("%d\n",a/tmp);
			else printf("%d/%d\n",a/tmp,b/tmp);
		}
		else printf("0\n");
	}
	return 0;
}
