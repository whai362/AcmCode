#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int i,flag,a[6];
	float ans;
	while(1){
		flag=1;
		for(i=0;i<6;++i){ cin>>a[i]; if(a[i]) flag=0; }
		if(flag) break;
		sort(a,a+6);
		ans=0;
		for(i=1;i<5;++i) ans=ans+a[i];
		cout<<ans/4<<endl;
	}
	return 0;
}
