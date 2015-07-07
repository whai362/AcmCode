#include<iostream>
#include<cstdio>
using namespace std;
int _abs(int x){
	if(x<0) return -x;
	else return x;
}
int get_cnt(int x,int &cnt2,int &cnt3,int &cnt5){
	cnt2=0;
	cnt3=0;
	cnt5=0;
	while(x%2==0){ x/=2; ++cnt2;}
	while(x%3==0){ x/=3; ++cnt3;}
	while(x%5==0){ x/=5; ++cnt5;}
	return x;
}
int main(){
	int a,b;
	while(cin>>a>>b){
		int cnt1_2=0;
		int cnt1_3=0;
		int cnt1_5=0;
		int left1=get_cnt(a,cnt1_2,cnt1_3,cnt1_5);

		int cnt2_2=0;
		int cnt2_3=0;
		int cnt2_5=0;
		int left2=get_cnt(b,cnt2_2,cnt2_3,cnt2_5);
		if(left1!=left2){
			puts("-1");
			continue;
		}
		//cout<<cnt1_2<<' '<<cnt1_3<<' '<<cnt1_5<<endl;
		int ans=_abs(cnt1_2-cnt2_2)+_abs(cnt1_3-cnt2_3)+_abs(cnt1_5-cnt2_5);
		cout<<ans<<endl;
	}
	return 0;
}
