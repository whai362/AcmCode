#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+5;
char S[N],T[N];
int del[N];
int n;
bool jg(char s[],char t[]){
	int p=0,q=0;
	//cout<<s<<' '<<t<<endl;
	while(p<n && q<n){
		//cout<<p<<' '<<q<<endl;
		if(del[p]==1){
			++p;
		}
		if(s[p]==t[q]){
			++p;
			++q;
		}
		else{
			++q;
		}
	}
	//cout<<p<<' '<<n<<endl;
	if(p==n) return true;
	else return false;
}
int main(){
	scanf("%d",&n);
	scanf("%s%s",S,T);
	for(int i=0;i<n;++i){
		if(S[i]!=T[i]){
			del[i]=1;
			break;
		}
	}
	int ans=0;
	if(jg(S,T)) ++ans;
   	if(jg(T,S)) ++ans;
	printf("%d\n",ans);
	return 0;
}
