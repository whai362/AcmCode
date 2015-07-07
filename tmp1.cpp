#include <iostream>
using namespace std;
int main(){
	int n,m;
	int inv[n];
	int sort[m]; 
	char si[m][n+5];
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>si[i];
		for(int j=0;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(si[i][j]>si[i][k])
					inv[i]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		sort[i]=0;
		int p=inv[0];
		for(int k=1;k<m;k++){
			if(p>inv[k]){
				p=inv[k];
				sort[i]=k;
			}
			inv[sort[i]]=1500;
		}
	}
	for(int i=0;i<m;i++)
		cout<<si[sort[i]]<<endl;
	return 0; 
}

