#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int n,a,b;
int d[100005];
bool vis[100005];
map<int,int> _map;
bool ok1(int x){
	if(_map.find(a-x)!=_map.end() && ( _map.find(b-x)==_map.end() || _map.find(a-(b-x))!=_map.end() )){
		if(_map.find(b-(a-x))==_map.end())
			return true;
		else if(_map.find(a-(b-(a-x)))!=_map.end()){
			return true;
		}
		else return false;
	}
	return false;
}
bool ok2(int x){
	if(_map.find(b-x)!=_map.end() && ( _map.find(a-x)==_map.end() || _map.find(b-(a-x))!=_map.end() )){
		if(_map.find(a-(b-x))==_map.end())
			return true;
		else if(_map.find(b-(a-(b-x)))!=_map.end())
			return true;
		else return false;
	}
	return false;
}
char out[2*100005],ans[100005];
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<n;++i){
		scanf("%d",&d[i]);
		_map.insert(make_pair(d[i],i));
	}
	memset(vis,0,sizeof(vis));
	memset(out,0,sizeof(out));
	memset(ans,0,sizeof(ans));
	int flag=1;
	for(int i=0;i<n;++i){
		if(vis[i]==false){
			if(ok1(d[i])){
				//cout<<'!'<<endl;
				int it=_map[d[i]];
				//cout<<1<<':'<<endl;
				//cout<<it<<endl;
				ans[it]='0';
				vis[it]=true;
				it=_map[a-d[i]];
				//cout<<it<<endl;
				ans[it]='0';
				vis[it]=true;
			}
			else if(ok2(d[i])){
				//cout<<2<<':'<<endl;
				int it=_map[d[i]];
				//cout<<it<<endl;
				ans[it]='1';
				vis[it]=true;
				it=_map[b-d[i]];
				//cout<<it<<endl;
				ans[it]='1';
				vis[it]=true;
			}
			else flag=0;
		}
	}
	for(int i=0;i<2*n;i+=2){
		out[i]=ans[i/2];
		if(i+1!=2*n-1) out[i+1]=' ';
	}
	if(flag){
		puts("YES");
		puts(out);
	}
	else puts("NO");
	return 0;
}
