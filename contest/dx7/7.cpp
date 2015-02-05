#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=2e5+5;
struct In{
	int x,y,u,v,c,id;
}in[2*N];
struct Data{
	int x,y,c;
	Data(){}
	Data(int _x,int _y,int _c){
		x=_x;
		y=_y;
		c=_c;
	}
};
int n,m,k,t;
int hr[N],hc[N];
vector<Data> row[N],col[N];
bool cmp1(In i1,In i2){
	return i1.u<i2.u;
}
bool cmp2(In i1,In i2){
	return i1.v<i2.v;
}
bool cmp3(In i1,In i2){
	return i1.id<i2.id;
} 
void read(){
	int i;
	for(i=0;i<k;++i){
		scanf("%d%d%d",&in[i].u,&in[i].v,&in[i].c);
		in[i].id=i;
	}
	//cout<<"!!!"<<endl;
	scanf("%d",&t);
	for(;i<k+t;++i){
		scanf("%d%d%d",&in[i].c,&in[i].u,&in[i].v);
		in[i].id=i;
	}
	sort(in,in+k+t,cmp1);
	in[0].x=1;
	for(int i=1;i<k+t;++i){
		if(in[i].u==in[i-1].u) in[i].x=in[i-1].x;
		else in[i].x=in[i-1].x+1;
	}
	sort(in,in+k+t,cmp2);
	in[0].y=1;
	for(int i=1;i<k+t;++i){
		if(in[i].v==in[i-1].v) in[i].y=in[i-1].y;
		else in[i].y=in[i-1].y+1;
	}
	sort(in,in+k+t,cmp3);
}
int main(){
	int cas=0,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<100005;++i){
			hr[i]=i;
			row[i].clear();
		}
		for(int i=0;i<100005;++i){
			hc[i]=i;
			col[i].clear();
		}
		read();
		//cout<<"!!!"<<endl;
		int i;
		for(i=0;i<k;++i){
			//cout<<in[i].x<<' '<<in[i].y<<' '<<in[i].c<<endl;
			row[in[i].x].push_back(Data(in[i].x,in[i].y,in[i].c));
			col[in[i].y].push_back(Data(in[i].x,in[i].y,in[i].c));
		}
		printf("Case #%d:\n",++cas);
		for(;i<k+t;++i){
			//cout<<in[i].x<<' '<<in[i].y<<' '<<in[i].c<<endl;
			if(in[i].c==1){
				int sz1=row[hr[in[i].x]].size(),
					sz2=row[hr[in[i].y]].size();
				if((sz1>0 && sz2>0) || (sz1==0 && sz2==0))
					swap(hr[in[i].x],hr[in[i].y]);
			}
			else if(in[i].c==2){
				int sz1=col[hc[in[i].x]].size(),
					sz2=col[hc[in[i].y]].size();
				if((sz1>0 && sz2>0) || (sz1==0 && sz2==0))
					swap(hc[in[i].x],hc[in[i].y]);
			}
			else{
				int ans=0;
				int sr=row[hr[in[i].x]].size(),
					sc=col[hc[in[i].y]].size();
				if(sr<=sc){
					for(int j=0;j<sr;++j){
						Data ch=row[hr[in[i].x]][j];
						if(hc[ch.y]==in[i].y){
							ans=ch.c;
							break;
						}
					}
				}
				else{
					for(int j=0;j<sc;++j){
						Data ch=col[hc[in[i].y]][j];
						if(hr[ch.x]==in[i].x){
							ans=ch.c;
							break;
						}
					}
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
