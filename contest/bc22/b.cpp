#include<iostream>
#include<cstdio>
using namespace std;
int a[4],b[4];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<4;++i){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		int _min=a[0];
		for(int i=0;i<3;++i)
			_min=min(_min,a[i]);
		for(int i=0;i<3;++i)
			a[i]-=_min;
		_min=a[1];
		for(int i=1;i<4;++i)
			_min=min(_min,a[i]);
		for(int i=1;i<4;++i)
			a[i]-=_min;
		int flag=1;
		for(int i=0;i<4;++i){
			if(a[i]%3!=0) flag=0;
		}
		if(flag==0){
			for(int i=0;i<4;++i)
				a[i]=b[i];
			_min=a[0];
			for(int i=0;i<4;++i)
				_min=min(_min,a[i]);
			for(int i=0;i<4;++i)
				a[i]-=_min;
			flag=1;
			for(int i=0;i<4;++i){
				if(a[i]%3!=0) flag=0;
			}
			if(flag) puts("Yes");
			else puts("No");
		}
		else{
			puts("Yes");
		}
	}
	return 0;
}
