#include<cstdio>
#include<cstring>
using namespace std;
char n[20],n1[20],n2[20];
double p,d;
int main(){
	int i,j,len;
	double ans;
	scanf("%lf%lf",&p,&d);
	sprintf(n1,"%.0f",p);
	//sprintf(n2,"%.0f",p-d);
	len=strlen(n1);
	for(i=0;i<len;++i){
		ans=0;
		memset(n,0,sizeof(n));
		while(ans<p-d || ans>=p){
			for(j=0;j<i;++j) n[j]=n1[j];
			if(n1[j]) n[j]=n1[j]-1;
			else n[j]='9';
			sscanf(n,"%lf",&ans);
		}
	}
	return 0;
}
