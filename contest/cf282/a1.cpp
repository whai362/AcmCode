#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define pb push_back
const int N=10;
vector<int> v[N];
int vis[10][10];
int main(){
	v[0].pb(0);
	v[0].pb(8);
	
	v[1].pb(0);
	v[1].pb(1);
	v[1].pb(3);
	v[1].pb(4);
	v[1].pb(7);
	v[1].pb(8);
	v[1].pb(9);

	v[2].pb(2);
	v[2].pb(8);
	
	v[3].pb(3);
	v[3].pb(8);
	v[3].pb(9);

	v[4].pb(4);
	v[4].pb(8);
	v[4].pb(9);

	v[5].pb(5);
	v[5].pb(6);
	v[5].pb(8);
	v[5].pb(9);

	v[6].pb(6);
	v[6].pb(8);
	
	v[7].pb(0);
	v[7].pb(3);
	v[7].pb(7);
	v[7].pb(8);
	v[7].pb(9);

	v[8].pb(8);
	
	v[9].pb(8);
	v[9].pb(9);
	
	char str[5];
	scanf("%s",str);
	int cnt=0;

	for(int i=0;i<v[str[0]-'0'].size();++i){
		for(int j=0;j<v[str[1]-'0'].size();++j){
			if(vis[i][j]==0){
				++cnt;
				vis[i][j]=1;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
