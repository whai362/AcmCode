#include <iostream>
#include <cstdio>
using namespace std;
int a[105][105],ans[105][105];
int r,c;
bool in(int i,int j){
	if(i>=1 && i<=r && j>=1 && j<=c)
		return true;
	return false;
}
int dfs(int i,int j){
	if(ans[i][j])
		return ans[i][j];
	else{
		if(in(i-1,j) && a[i][j]>a[i-1][j]) ans[i][j]=max(ans[i][j],dfs(i-1,j));
		if(in(i,j-1) && a[i][j]>a[i][j-1]) ans[i][j]=max(ans[i][j],dfs(i,j-1));
		if(in(i+1,j) && a[i][j]>a[i+1][j]) ans[i][j]=max(ans[i][j],dfs(i+1,j));
		if(in(i,j+1) && a[i][j]>a[i][j+1]) ans[i][j]=max(ans[i][j],dfs(i,j+1));
		++ans[i][j];
		return ans[i][j];	
	}
}
int main(){
	cin>>r>>c;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++)
			scanf("%d",&a[i][j]);
	}
	int length=0;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			int k=0;
			int temp=dfs(i,j);
			if(temp>length) length=temp;
		}
	}
	cout<<length<<endl;
	return 0;
}
