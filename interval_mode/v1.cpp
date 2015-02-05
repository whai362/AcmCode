#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=100005,
	  M=200005;
int n,m,cnt,mg,mg_cnt;
int a[N],
	sorted[N],
	hash[N];
struct Data{
	int x,f;
}dp[1005][1005];
vector<int> _map[N];
void predo(){
	sort(sorted,sorted+n);
	cnt=unique(sorted,sorted+n)-sorted;
	for(int i=0;i<n;++i){
		a[i]=lower_bound(sorted,sorted+cnt,a[i])-sorted;
	}
	
	//for(int i=0;i<n;++i){
	//	cout<<a[i]<<' ';
	//}
	//cout<<endl;

	for(int i=0;i<n;++i)
		_map[a[i]].pb(i);
	for(int i=0;i<n;++i)
		sort(_map[i].begin(),_map[i].end());

	mg=sqrt(double(n));
	mg_cnt=n/mg;
	int _maxx=N+1,_maxf=0;
	if(n%mg) ++mg_cnt;
	for(int i=0;i<mg_cnt;++i){
		int from=i,to;
		memset(hash,0,sizeof(hash));
		_maxf=0,_maxx=N+1;
		for(int j=i*mg;j<n;++j){
			++hash[a[j]];
			if(hash[a[j]]>_maxf){
				_maxf=hash[a[j]];
				_maxx=a[j];
			}
			else if(hash[a[j]]==_maxf){
				_maxx=min(_maxx,a[j]);
			}
			if((j+1)%mg==0 || j+1==n){
				to=(j+1)/mg-1;
				if((j+1)%mg) ++to;
				dp[from][to].x=_maxx;
				dp[from][to].f=_maxf;
			}
		}
	}
}
int get_cnt(int l,int r,int x){
	int ret;
	//cout<<l<<' '<<r<<' '<<x<<endl;
	//cout<<upper_bound(_map[x].begin(),_map[x].end(),r)-_map[x].begin()<<endl;
	//cout<<lower_bound(_map[x].begin(),_map[x].end(),l)-_map[x].begin()<<endl;
	ret=upper_bound(_map[x].begin(),_map[x].end(),r)-lower_bound(_map[x].begin(),_map[x].end(),l);
	return ret;
}
int query(int left,int right){
	//cout<<left<<' '<<right<<endl;
	--left,--right;
	int l=left/mg,r=right/mg;
	int ansx=N+1,ansf=0;
	if(l==r || l+1==r){
		memset(hash,0,sizeof(hash));	
		for(int i=left;i<=right;++i){
			++hash[a[i]];
			if(hash[a[i]]>ansf){
				ansf=hash[a[i]];
				ansx=a[i];
			}
			else if(hash[a[i]]==ansf){
				ansx=min(ansx,a[i]);
			}
		}
		return sorted[ansx];
	}
	else{
		int l1=l+1,r1=r-1;
		ansx=dp[l1][r1].x,
		ansf=dp[l1][r1].f;
		int zuo=l1*mg,you=r*mg-1;
		memset(hash,0,sizeof(hash));
		for(int i=left;i<l1*mg;++i){
			++hash[a[i]];
			int oth=get_cnt(zuo,you,a[i]);
			int sum=hash[a[i]]+oth;
			if(sum>ansf){
				ansf=sum;
				ansx=a[i];
			}
			else if(sum==ansf){
				ansx=min(ansx,a[i]);
			}
		}
		for(int i=r*mg;i<=right;++i){
			++hash[a[i]];
			int oth=get_cnt(zuo,you,a[i]);
			int sum=hash[a[i]]+oth;
			if(sum>ansf){
				ansf=sum;
				ansx=a[i];
			}
			else if(sum==ansf){
				ansx=min(ansx,a[i]);
			}
		}
	}
	return sorted[ansx];
}
int main(){
	double start=clock(),end;
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		sorted[i]=a[i];
	}
	predo();
	//int l,r,x;
	//while(cin>>l>>r>>x){
	//	cout<<get_cnt(l,r,x)<<endl;
	//}
	int l,r;
	for(int i=0;i<m;++i){
		scanf("%d%d",&l,&r);
		l=(l+ans-1)%n+1;
		r=(r+ans-1)%n+1;
		if(l>r) swap(l,r);
		ans=query(l,r);
		printf("%d\n",ans);
	}
	end=clock();
	cerr<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
	return 0;
}
