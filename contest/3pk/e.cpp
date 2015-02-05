#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,a[5005];
int work(int k){
	int cnt=0,i,flag=0,op=0,_max=0;
	queue<int> q;
	for(i=0;i<n;++i){
		if(_max<=n){
			if(q.empty()){
				if(a[i]==0){
					flag=1;
					++op;
					q.push(i+k);
					if(i+k<=n) ++cnt;	//关键点无效的情况
					_max=max(_max,i+k);
					//cout<<i<<' '<<i+k<<endl;
				}
				else ++cnt;
			}
			else{
				if(i<q.front()){
					if(a[i]==flag){
						flag=!flag;
						++op;
						q.push(i+k);
						if(i+k<=n) ++cnt;
						_max=max(_max,i+k);
						//cout<<i<<' '<<i+k<<endl;
					}
					else ++cnt;
				}
				else{
					q.pop();
					if(q.empty()){
						if(a[i]==0){
							flag=1;
							++op;
							q.push(i+k);
							if(i+k<=n) ++cnt;
							_max=max(_max,i+k);
							//cout<<i<<' '<<i+k<<endl;
						}
						else ++cnt;
					}
					else{
						flag=!flag;
						if(a[i]==flag){
							flag=!flag;
							++op;
							q.push(i+k);
							if(i+k<=n) ++cnt;
							_max=max(_max,i+k);
							//cout<<i<<' '<<i+k<<endl;
						}
						else ++cnt;
					}
				}
			}
		}
	}
	//cout<<"!: "<<cnt<<' '<<op<<endl;
	//cout<<endl<<endl;
	if(cnt==n) return op;
	else return -1;
}
int main(){
	char s[2];
	int i,j,ansk,ansm,tmp;
	scanf("%d",&n);
	ansm=0x3f3f3f3f;
	for(i=0;i<n;++i){
		scanf("%s",s);
		if(s[0]=='B') a[i]=0;
		else a[i]=1;
	}
	for(i=1;i<=n;++i){
		tmp=work(i);
		if(tmp!=-1 && tmp<ansm) ansk=i,ansm=tmp;
	}
	printf("%d %d\n",ansk,ansm);
	return 0;
}
