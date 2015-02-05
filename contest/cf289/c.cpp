#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
vector<int> ans[305];
int in[305];
int c[300];
int main(){
	int n;
	int a;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&in[i]);
		a=in[i];
		if(i==0){
			while(a>9){
				ans[i].push_back(9);
				a-=9;
			}
			ans[i].push_back(a);
		}
		else{
			if(a>in[i-1]){
				a-=in[i-1];
				for(int j=0;j<ans[i-1].size();++j){
					if(a>9-ans[i-1][j]){
						ans[i].push_back(9);
						a-=9-ans[i-1][j];
					}
					else{
						ans[i].push_back(ans[i-1][j]+a);
						a=0;
					}
				}
				while(a>9){
					ans[i].push_back(9);
					a-=9;
				}
				if(a) ans[i].push_back(a);
			}
			else{
				int flag=0;
				int t=in[i-1]-a+1;
				//memset(c,0,sizeof(c));
				for(int j=0;j<ans[i-1].size();++j){
					if(t>0){
						t-=ans[i-1][j];
						ans[i].push_back(0);
					}
					else if(flag==0 && ans[i-1][j]==9){
						t-=ans[i-1][j];
						ans[i].push_back(0);
					}
					else{
						if(flag==0){
							ans[i].push_back(ans[i-1][j]+1);
							flag=1;
						}
						else{
							ans[i].push_back(ans[i-1][j]);
						}
					}
				}
				if(flag==0){
					ans[i].push_back(1);
				}
				t=-t;
				for(int j=0;j<ans[i].size();++j){
					if(t>9-ans[i][j]){
						t-=9-ans[i][j];
						ans[i][j]=9;
					}
					else{
						ans[i][j]=ans[i][j]+t;
						t=0;
					}
				}
				while(t>9){
					ans[i].push_back(9);
					t-=9;
				}
				if(t) ans[i].push_back(t);
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=ans[i].size()-1;j>=0;--j){
			printf("%d",ans[i][j]);
		}
		puts("");
	}
	return 0;
}
