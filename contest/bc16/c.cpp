#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define LL __int64
map<LL,int> _map;
LL a[1005];
int main(){
	int n;
	LL xs;
	scanf("%d",&n);
	_map.clear();
	xs=0;
	for(int i=0;i<n;++i){
		scanf("%I64d",&a[i]);
		xs^=a[i];
	}
	int flag=0;
	for(int i=0;i<n;++i){
		LL tmp=xs^a[i];
		if(_map.find(tmp)==_map.end()){
			_map[tmp]=1;
		}
		else{
			flag=1;
			break;
		}
	}
	if(flag) puts("Yes");
	else puts("No");
	return 0;
}
