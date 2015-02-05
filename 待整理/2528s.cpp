/*代码风格<strong>更新</strong>后*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))
const int N=20005;

struct node
{
	int lft,rht,co;
	int mid(){return MID(lft,rht);}
};

int a[N],b[N],n;
vector<int> y;
bool flag[N/2];
map<int,int> H;

struct Segtree
{
	node tree[N*4];
	void build(int lft,int rht,int ind)
	{
		tree[ind].lft=lft;	tree[ind].rht=rht;
		tree[ind].co=0;
		if(lft+1!=rht)
		{
			int mid=tree[ind].mid();
			build(lft,mid,LL(ind));
			build(mid,rht,RR(ind));
		}
	}
	void updata(int st,int ed,int ind,int co)
	{
		int lft=tree[ind].lft,rht=tree[ind].rht;
		if(st<=lft&&rht<=ed) tree[ind].co=co;
		else 
		{
			if(tree[ind].co)
			{
				tree[LL(ind)].co=tree[ind].co;
				tree[RR(ind)].co=tree[ind].co;
				tree[ind].co=0;
			}
			int mid=tree[ind].mid();
			if(st<mid) updata(st,ed,LL(ind),co);
			if(ed>mid) updata(st,ed,RR(ind),co);
		}
	}
	void query(int st,int ed,int ind)
	{
		int lft=tree[ind].lft,rht=tree[ind].rht;
		if(tree[ind].co!=0||lft+1==rht) 
		{
			flag[tree[ind].co]=1;
			return;
		}
		query(st,ed,LL(ind));	query(st,ed,RR(ind));
	}
}seg;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		y.clear(); H.clear();

		scanf("%d",&n);
		for(int i=0;i<n;i++) 
		{
			flag[i]=0;
			scanf("%d%d",&a[i],&b[i]);
			b[i]++;
			y.push_back(a[i]); y.push_back(b[i]);
		}
		sort(y.begin(),y.end());
		y.erase(unique(y.begin(),y.end()),y.end());
		for(int i=0;i<(int)y.size();i++) H[y[i]]=i;

		int len=(int)y.size();
		seg.build(0,len-1,1);
		for(int i=0;i<n;i++) seg.updata(H[a[i]],H[b[i]],1,i+1);
		seg.query(1,len,1);
		int res=0;
		for(int i=1;i<=n;i++) if(flag[i]) res++;
		printf("%d\n",res);
	}
	return 0;
}

