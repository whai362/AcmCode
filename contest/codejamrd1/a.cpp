#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 155
#define L 40
char d[N][L],o[N][L];
int ans,n,l,flag,turn;
int a[2][2],b[2][2],d0,d1,o0,o1;
void judge(){
	if(a[0][0]==b[0][0] && a[0][1]==b[0][1] && a[1][0]==b[1][0] && a[1][1]==b[1][1]){
		turn=0;
		flag=0;
		return ;
	}
	if(a[0][0]==b[0][1] && a[0][1]==b[0][0] && a[1][0]==b[1][1] && a[1][1]==b[1][0]){
		turn=1;
		++ans;
		flag=0;
		return ;
	}
	flag=1;
}
int main(){
	int i,j,t;
	scanf("%d",&t);
	for(int l1=1;l1<=t;++l1){
	scanf("%d%d",&n,&l);
	ans=flag=turn=0;
	for(i=0;i<n;++i){
		scanf("%s",d[i]);
	}
	for(i=0;i<n;++i){
		scanf("%s",o[i]);
	}
	d0=d1=o0=o1=0;
	for(i=0;i<n;++i){
		if(d[i][0]=='0') ++d0;
		else ++d1;
	}
	for(i=0;i<n;++i){
		if(o[i][0]=='0') ++o0;
		else ++o1;
	}
	//cout<<d0<<' '<<d1<<endl;
	//cout<<o0<<' '<<o1<<endl;
	if(d0==o0 || d0==o1){
		if(d0!=o0 && d0==o1){
			++ans;
			turn=1;
		}
		else turn=0;
	}
	else flag=1;
	//cout<<"!: "<<flag<<' '<<turn<<endl;
	if(!flag){
		for(i=1;i<l;++i){
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			for(j=0;j<n;++j){
				++a[d[j][i-1]-'0'][d[j][i]-'0'];
			}
			for(j=0;j<n;++j){
				if(!turn)
					++b[o[j][i-1]-'0'][o[j][i]-'0'];
				else
					++b[!(o[j][i-1]-'0')][o[j][i]-'0'];
			}
			for(int i1=0;i1<2;++i1){
				for(int i2=0;i2<2;++i2){
					//cout<<a[i1][i2]<<' ';
				}
				//cout<<endl;
			}
			for(int i1=0;i1<2;++i1){
				for(int i2=0;i2<2;++i2){
					//cout<<b[i1][i2]<<' ';
				}
				//cout<<endl;
			}
			judge();
			if(flag) break;
		}
	}
	if(flag) printf("Case #%d: NOT POSSIBLE\n",l1);
	else printf("Case #%d: %d\n",l1,ans);
	}
	return 0;
}
