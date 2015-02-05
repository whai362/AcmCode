#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	__int64 i,t1,t2,x1,x2,t0,y1,y2,ans_y1,ans_y2;
	double tmp,tt,tt1,tt2,_min;
	cin>>t1>>t2>>x1>>x2>>t0;
	if(t2==t0) cout<<0<<' '<<x2<<endl;
	else{
	_min=100000000;
	for(i=x1;i>=0;--i){
		y2=(t0-t1)*i/(t2-t0);
		tmp=double(t1*i+t2*y2)/double(i+y2);
		if(tmp>=t0) tt1=fabs(tmp-double(t0));
		else tt1=1000000000;
		tmp=double(t1*i+t2*(y2+1))/double(i+y2+1);
		if(tmp>=t0) tt2=fabs(tmp-double(t0));
		else tt2=1000000000;
		if(tt1>=tt2) ++y2,tt=tt2;
		else tt=tt1;
		if(y2<=x2){
			//if(i==107 || i==76) cout<<tt<<endl;
			if(tt<_min) _min=tt,ans_y1=i,ans_y2=y2;
		}
	}
	if(ans_y1!=0) cout<<ans_y1<<' '<<ans_y2<<endl;
	else cout<<0<<' '<<x2<<endl;
	}
	return 0;
}

