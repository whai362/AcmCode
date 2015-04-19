#include<iostream>
#include<cstdio>
using namespace std;
bool ok(int x1,int y1,int x2,int y2,int t){
	if(x1<=x2 && y1<=y2){
		int tmp1=x2-x1;
		int tmp2=y2-y1;
		int nd=max(tmp1,tmp2);
		if(nd>=t) return true;
		return false;
	}
	return true;
}
int main(){
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if(x1>=x2 && y1>=y2){
		puts("Vasiliy");
		return 0;
	}
	int t,flag=1;
	for(int i=0;i<=x1;++i){
		t=x1-i;
		if(!ok(i,y1,x2,y2,t)){
			flag=0;
		}
	}
	for(int i=0;i<=y1;++i){
		t=y1-i;
		if(!ok(x1,i,x2,y2,t)){
			flag=0;
		}
	}
	if(flag) puts("Polycarp");
	else puts("Vasiliy");
	return 0;
}
