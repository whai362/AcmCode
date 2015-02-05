#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int r,g,b,b1,b2,b3,b4,cnt=0;
	scanf("%d%d%d",&r,&g,&b);
	if(r%3==0) ++cnt;
	if(g%3==0) ++cnt;
	if(b%3==0) ++cnt;
	if(cnt<=1){
		if(r && r%3==0) b1=r/3-1,r=3;
		else b1=r/3,r-=b1*3;
		if(g && g%3==0) b2=g/3-1,g=3;
		else b2=g/3,g-=b2*3;
		if(b && b%3==0) b3=b/3-1,b=3;
		else b3=b/3,b-=b3*3;
		b4=min(min(r,g),b);
	}
	else{
		b1=r/3,r-=b1*3;
		b2=g/3,g-=b2*3;
		b3=b/3,b-=b3*3;
		b4=min(min(r,g),b);
	}
	//cout<<b1<<' '<<b2<<' '<<b3<<' '<<b4<<endl;
	printf("%d\n",b1+b2+b3+b4);
	return 0;
}

