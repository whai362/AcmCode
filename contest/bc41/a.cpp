#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N=1e3+5;
int h[N];
char str[5];
int ans;
void gao(char str[]){
	int len=strlen(str);
	int hua,num;
	hua=(str[0]-'A')*100;
	if(len==2){
		num=str[1]-'0'-1;
	}
	else{
		num=(str[1]-'0')*10+str[2]-'0'-1;
	}
	for(int i=num;i<min(num+5,14);++i){
		int tmp=hua+i%13;
		//cout<<tmp<<' ';
		++h[tmp];
		ans=max(ans,h[tmp]);
	}
	for(int i=(num-1+14)%14;i>=max(0,(num-4+14)%14);--i){
		int tmp=hua+i;
		//cout<<tmp<<' ';
		++h[tmp];
		ans=max(ans,h[tmp]);
	}
	//cout<<endl;
	//cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(h,0,sizeof(h));
		ans=0;
		for(int i=0;i<5;++i){
			scanf("%s",str);
			gao(str);
		}
		printf("%d\n",5-ans);
	}
	return 0;
}
