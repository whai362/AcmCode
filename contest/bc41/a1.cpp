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
void deal(char str[]){
	int len=strlen(str);
	int hua,num;
	hua=(str[0]-'A')*100;
	if(len==2)
		num=str[1]-'0'-1;
	else
		num=(str[1]-'0')*10+str[2]-'0'-1;
	h[hua+num]=1;
}
void gao(){
	for(int i=0;i<4;++i){
		int hua=i*100,num;
		for(int j=0;j<=9;++j){
			int tmp=0;
			for(int k=j;k<j+5;++k){
				num=k%13;
				tmp+=h[hua+num];
			}
			ans=max(ans,tmp);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(h,0,sizeof(h));
		ans=0;
		for(int i=0;i<5;++i){
			scanf("%s",str);
			deal(str);
		}
		gao();
		printf("%d\n",5-ans);
	}
	return 0;
}
