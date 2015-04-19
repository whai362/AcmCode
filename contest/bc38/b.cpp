#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=1e5+5;
int h[N];
void In(int &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

void In(LL &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

int main(){
	int T;
	int cas=0;
	In(T);
	while(T--){
		memset(h,0,sizeof(h));
		int n,a;
		int _max=0;
		In(n);
		for(int i=0;i<n;++i){
			In(a);
			//cout<<a<<' ';
			_max=max(_max,a);
			++h[a];
		}
		//cout<<endl;
		//cout<<_max<<endl;
		int ans=1;
		for(int i=1;i<=_max;++i){
			int cnt=0;
			for(int j=1;j*i<=_max;++j){
				cnt+=h[j*i];
			}
			if(cnt>=2){
				ans=max(ans,i);
			}
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}
