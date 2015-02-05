#include<iostream>
using namespace std;
int main(){
	int i;
	__int64 a,b;
	cin>>a>>b;
	if(a>=b){
		__int64 aa,bb;
		aa=b/2;
		bb=b-aa;
		cout<<a*a-aa*aa-bb*bb<<endl;
		for(i=0;i<aa;++i)
			cout<<"x";
		for(i=0;i<a;++i)
			cout<<"o";
		for(i=0;i<bb;++i)
			cout<<"x";
		cout<<endl;
	}
	else{
		int i,j;
		__int64 ans=0;
		__int64 t1,t2;
		t1=b/(a+1);
		t2=b-t1*a;
		ans=(-t1*t1+1)*a-t2*t2;
		//cout<<t1<<' '<<t2<<endl;
		cout<<ans<<endl;
		for(i=0;i<a;++i){
			for(j=0;j<t1;++j)
				cout<<'x';
			cout<<'o';
		}
		for(i=0;i<t2;++i)
			cout<<'x';
		cout<<endl;
	}
	return 0;
}
