#include<iostream>
#include<string>
using namespace std;
int _mod1[]={0,1,2,3,4,5,6},
	_mod2[]={0,4,5},
	_mod3[]={0,6,3,1,2,5},
	_mod4[]={0,4,6},
	_mod5[]={0,3,4,2,6,5},
	_mod6[]={0,1};
int a[8],ni[8];
int main(){
	int ans,n,t,T;
	int i;
	string w[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	cin>>T;
	while(T--){
	cin>>n;
	ans=0;
	t=n/7;
	for(i=1;i<=7;++i){
		ni[i]=t;
	}
	t=n%7;
	for(i=0;i<t;++i){
		++ni[i+1];
	}
	a[1]=_mod1[ni[1]%7];
	a[2]=_mod2[ni[2]%3];
	a[3]=_mod3[ni[3]%6];
	a[4]=_mod4[ni[4]%3];
	a[5]=_mod5[ni[5]%6];
	a[6]=_mod6[ni[6]%2];
	a[7]=0;
	for(i=1;i<=7;++i){
		ans+=a[i];
		ans%=7;
	}
	//cout<<ans%7<<endl;
	cout<<w[(6+ans)%7]<<endl;
	}
	return 0;
}
