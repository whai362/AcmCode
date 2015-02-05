#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
#define LL __int64
const int N=1e5+5;
LL a[N];
map<int,int> in,nd;
vector<int> bg1;
int bag[5];
int main(){
	int n;
	LL l,x,y;
	scanf("%d%I64d%I64d%I64d",&n,&l,&x,&y);
	for(int i=0;i<n;++i){
		scanf("%I64d",&a[i]);
		in[a[i]]=1;
	}
	int flag1=0;
	for(int i=0;i<n;++i){
		LL tmp=a[i]+x;
		if(tmp<=l){
			if(in.find(tmp)!=in.end()) flag1=1;
			else nd[tmp]=1,bg1.push_back(tmp);
		}
		tmp=a[i]-x;
		if(tmp>=0){
			if(in.find(tmp)!=in.end()) flag1=1;
			else nd[tmp]=1,bg1.push_back(tmp);
		}
	}
	if(flag1) nd.clear(),bg1.clear();
	/*for(int i=0;i<bg1.size();++i){
		cout<<bg1[i]<<' ';
	}*/
	//cout<<endl;
	int ans=2;
	for(int i=0;i<n;++i){
		LL tmp=a[i]+y;
		if(tmp<=l){
			int y1=0;
			if(in.find(tmp)!=in.end())
				y1=1;
			int y2=0;
			if(nd.find(tmp)!=nd.end())
				y2=1;
			//cout<<tmp<<' '<<flag1<<' '<<y1<<' '<<y2<<endl;
			if(flag1==0 && y1==0 && y2==0){ ans=min(ans,2);if(ans==2) bag[0]=bg1[0],bag[1]=tmp; }
			if(flag1==0 && y1==0 && y2==1){ ans=min(ans,1);if(ans==1) bag[0]=tmp; }
			if(flag1==0 && y1==1){ ans=min(ans,1);if(ans==1) bag[0]=bg1[0]; }
			if(flag1==1 && y1==0){ ans=min(ans,1);if(ans==1) bag[0]=tmp; }
			if(flag1==1 && y1==1) ans=min(ans,0);
			//cout<<bag[0]<<endl;
		}
		tmp=a[i]-y;
		if(tmp>=0){
			int y1=0;
			if(in.find(tmp)!=in.end())
				y1=1;
			int y2=0;
			if(nd.find(tmp)!=nd.end())
				y2=1;
			//cout<<tmp<<' '<<flag1<<' '<<y1<<' '<<y2<<endl;
			if(flag1==0 && y1==0 && y2==0){ ans=min(ans,2);if(ans==2) bag[0]=bg1[0],bag[1]=tmp; }
			if(flag1==0 && y1==0 && y2==1){ ans=min(ans,1);if(ans==1) bag[0]=tmp; }
			if(flag1==0 && y1==1){ ans=min(ans,1);if(ans==1) bag[0]=bg1[0]; }
			if(flag1==1 && y1==0){ ans=min(ans,1);if(ans==1) bag[0]=tmp; }
			if(flag1==1 && y1==1) ans=min(ans,0);
			//cout<<bag[0]<<endl;
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<ans;++i){
		printf("%d%c",bag[i],i+1!=ans?' ':'\n');
	}
	return 0;
}
