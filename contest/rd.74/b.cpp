#include<iostream>
using namespace std;
int main(){
	__int64 x,y,m,cnt=0;
	cin>>x>>y>>m;
	if(max(x,y)<=0 && max(x,y)<m){
		cout<<-1<<endl;
	}
	else{
		__int64 t;
		if(x>y){
			t=x;
			x=y;
			y=t;
		}
		while(y<m){
			if(x>0){
				t=y;
				y=x+y;
				x=t;
				++cnt;
			}
			else{
				cnt=-x/y+1;
				x+=cnt*y;

			}
		}
		cout<<cnt<<endl;
	}
}
