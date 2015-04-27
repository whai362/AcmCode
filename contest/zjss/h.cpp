#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int whatday(int d,int m,int y){
	int ans;
	if(m==1 || m==2){
		m+=12;
		y--;
	}
	ans=(d+2*m+3*(m+1)/5 + y + y/4 -y/100 +y/400)%7;
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int y;
		scanf("%d",&y);
		int pre=whatday(30,4,y);
		int bac=whatday(6,5,y);
		int ans=5;
		if(pre==6) ans+=2;
		else if(pre==5) ans+=1;
		if(bac==5) ans+=2;
		else if(bac==6) ans+=1;
		printf("%d\n",ans);
	}
	return 0;
}
