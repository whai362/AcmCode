#include<iostream>
#include<cstdio>
using namespace std;
int a[20];
int main(){
	int T;
	int n;
	scanf("%d",&T);
	int lim=10000;
	int cnt=0;
	while(T--){
		scanf("%d",&n);
		int _max=-1000000,_min=-_max,maid=0,miid=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			if(a[i]>_max) _max=a[i],maid=i;
			if(a[i]<_min) _min=a[i],miid=i;
		}

		while(cnt<lim && _max!=_min){
			a[miid]=a[maid]=_max-_min;
			_max=-1000000,_min=-_max;
			for(int i=0;i<n;++i){
				if(a[i]>_max) _max=a[i],maid=i;
				if(a[i]<_min) _min=a[i],miid=i;
			} 
			//cout<<_max<<' '<<_min<<endl;
			//++cnt;
		}
		//if(cnt==lim) puts("Nooooooo!");
		//else{
			printf("%d\n",_max);
		//}
	}
	return 0;
}
