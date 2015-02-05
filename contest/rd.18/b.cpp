#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int a,int b){
	if(b) return gcd(b,a%b);
	return a;
}

int Abs(int a){
	if(a<0) return -a;
	return a;
}

int main(){
	int i,n,m,tmp,a[105],b[105];
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;++i) scanf("%d",&a[i]);
	for(i=0;i<=m;++i) scanf("%d",&b[i]);
	if(n>m){
		if(a[0]*b[0]>0) printf("Infinity\n");
		else printf("-Infinity\n");
	}
	else if(n<m){
		printf("0/1\n");
	}
	else{
		tmp=Abs(gcd(a[0],b[0]));
		if(tmp<0) tmp=-tmp;
		if(a[0]*b[0]<0) printf("-%d/%d\n",Abs(a[0])/tmp,Abs(b[0])/tmp);
		else printf("%d/%d\n",Abs(a[0])/tmp,Abs(b[0])/tmp);
	}
	return 0;
}
