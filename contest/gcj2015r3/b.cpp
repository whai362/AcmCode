#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int N=10;
char key[N];
char tar[N];
int cnt[30];
void gao(int k,int l,int s){
	int cd=l;
	//cout<<"!"<<endl;
	for(int i=1;i<l;++i){
		int flag=1;
		for(int j=0;i+j<l;++j){
			if(tar[j]!=tar[i+j]){
				flag=0;
				break;
			}
		}
		if(flag){
			cd=i;
			break;
		}
	}
	//cout<<cd<<endl;
	//cout<<"!"<<endl;
	
	double _max=(s-l)/cd+1;
	//cout<<_max<<endl;
	double qw=(s-l);
	for(int i=0;i<l;++i){
		qw*=(double)cnt[tar[i]-'A'];
	}
	for(int i=0;i<2*l-s;++i){
		qw/=(double)k;
	}
	//cout<<qw<<endl;
	printf("%.7f\n",_max-qw);
}
int main(){
	int T;
	int k,l,s;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		scanf("%d%d%d",&k,&l,&s);
		scanf("%s%s",key,tar);
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<k;++i){
			++cnt[key[i]-'A'];
		}
		printf("Case #%d: ",++cas);
		gao(k,l,s);
	}
	return 0;
}
