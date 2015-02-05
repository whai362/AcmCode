#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int N=1005;
int ans[N];
int cnt=0;
char s[N][N];
string row[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%s",s[i]);
	for(int i=0;i<m;++i){
		int flag=1;
		for(int j=1;j<n;++j){
			if(row[j]==row[j-1] && s[j][i]<s[j-1][i]){
				++cnt;
				flag=0;
				ans[i]=1;
				break;
			}
		}
		if(flag)
			for(int j=0;j<n;++j){
				row[j]+=s[j][i];
			}
	}
	//for(int i=0;i<n;++i)
	//	cout<<row[i]<<endl;
	printf("%d\n",cnt);
	return 0;
}
