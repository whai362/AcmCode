#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool _map[55][105];
int s,cnt,a[15];
bool ok(int x,int y){
	if(x>=0 && x<2*s && y>=0 && y<4*s)
		return true;
	return false;
}
bool canFill(int x,int y,int n){
	if(y%2){
		for(int i=x;i<x+a[n];++i){
			for(int j=y-2*(i-x);j<=y;++j){
				//cout<<"!!!"<<i<<' '<<j<<endl;
				if(!(ok(i,j) && _map[i][j]==true))
					return false;
			}
		}
		return true;
	}
	else{
		for(int i=x;i<x+a[n];++i){
			for(int j=y;j<y+2*a[n]-1-2*(i-x);++j){
				//cout<<"!!!"<<i<<' '<<j<<endl;
				if(!(ok(i,j) && _map[i][j]==true))
					return false;
			}
		}
		return true;
	}
}
void fill(int x,int y,int n){
	if(y%2){
		for(int i=x;i<x+a[n];++i){
			for(int j=y-2*(i-x);j<=y;++j){
				_map[i][j]=false;
			}
		}
	}
	else{
		for(int i=x;i<x+a[n];++i){
			for(int j=y;j<y+2*a[n]-1-2*(i-x);++j){
				_map[i][j]=false;
			}
		}
	}
}
void unfill(int x,int y,int n){
	if(y%2){
		for(int i=x;i<x+a[n];++i){
			for(int j=y-2*(i-x);j<=y;++j){
				_map[i][j]=true;
			}
		}
	}
	else{
		for(int i=x;i<x+a[n];++i){
			for(int j=y;j<y+2*a[n]-1-2*(i-x);++j){
				_map[i][j]=true;
			}
		}
	}
}
void print(){
	for(int i=0;i<2*s;++i){
		for(int j=0;j<4*s;++j){
			cout<<_map[i][j];
		}
		cout<<endl;
	}
}
bool dfs(int x,int y){
	//cout<<x<<' '<<y<<endl;
	if(x>=2*s)
		return true;
	if(y>=4*s)
		return dfs(x+1,0);
	if(!_map[x][y]){
		while(!_map[x][y]){
			++y;
		}
		return dfs(x,y);
	}
	for(int i=0;i<cnt;++i){
		if(canFill(x,y,i)){
			fill(x,y,i);
			//cout<<endl;
			//print();
			if(dfs(x,y+1))
				return true;
			unfill(x,y,i);
		}
	}
	return false;
}
int main(){
	int n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&s,&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		bool flag=false;
		for(int i=0;i<n;++i){
			if(s%a[i]==0){
				flag=true;
				break;
			}
		}
		if(flag==true)
			printf("YES\n");
		else{
		memset(_map,0,sizeof(_map));
		for(int i=0;i<s;++i){
			for(int j=2*s-1-2*i;j<4*s;++j){
				_map[i][j]=true;
			}
		}
		for(int i=s;i<2*s;++i){
			for(int j=0;j<4*s-1-2*(i-s);++j){
				_map[i][j]=true;
			}
		}
		cnt=0;
		for(;cnt<n;++cnt){
			if(a[cnt]>s)
				break;
		}
		for(int i=1;i<cnt;++i){
			for(int j=0;j<i;++j){
				if(a[i]%a[j]==0){
					for(int k=cnt-1;k>i;--k){
						a[k-1]=a[k];
					}
					--i;
					--cnt;
					break;
				}
			}
		}
		//print();
		int ans=dfs(0,0);
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
		}
	}
	return 0;
}
