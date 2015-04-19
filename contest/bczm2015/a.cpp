#include<iostream>
#include<cstdio>
using namespace std;
string tab[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
int getM(string str){
	for(int i=0;i<12;++i){
		if(str==tab[i]) return i+1;
	}
	return 0;
}
bool isleap(int x){
	if(x%400==0 || x%100 && x%4==0) return true;
	return false;
}
int leap(int x){
	return x/4-x/100+x/400;
}
void gao(int y1,int m1,int d1,int y2,int m2,int d2){
	int ans=0;
	if(isleap(y1)){
		if(m1<2 || (m1==2 && d1<=29)) ++ans;
	}
	if(isleap(y2)){
		if(m2>2 || (m2==2 && d2>=29)) ++ans;
	}
	ans+=leap(y2-1)-leap(y1);
	printf("%d\n",ans);
}
int main(){
	int T;
	int cas=0;
	cin>>T;
	string mo,ch;
	int m1,m2,d1,d2,y1,y2;
	while(T--){
		cin>>mo>>d1>>ch>>y1;
		m1=getM(mo);
		//cout<<y1<<' '<<m1<<' '<<d1<<endl;
		cin>>mo>>d2>>ch>>y2;
		m2=getM(mo);
		//cout<<y2<<' '<<m2<<' '<<d2<<endl;
		printf("Case #%d: ",++cas);
		gao(y1,m1,d1,y2,m2,d2);
	}
	return 0;
}
