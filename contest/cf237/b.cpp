#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	double a,d,tmp;
	__int64 i,n,t1;
	scanf("%lf%lf%I64d",&a,&d,&n);
	for(i=1;i<=n;++i){
		tmp=i*d;
		t1=(__int64)(tmp/a);
		tmp-=t1*a;
		t1=t1%4;
		//cout<<"!"<<t1<<' '<<tmp<<endl;
		if(t1==0){
			printf("%.10lf %.10lf\n",tmp,0.0);
		}
		else if(t1==1){
			printf("%.10lf %.10lf\n",a,tmp);
		}
		else if(t1==2){
			printf("%.10lf %.10lf\n",a-tmp,a);
		}
		else if(t1==3){
			printf("%.10lf %.10lf\n",0.0,a-tmp);
		}
	}
	return 0;
}
