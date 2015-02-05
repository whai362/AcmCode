#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define mp make_pair
const int N=10005,
	  M=20005;
int n,m,cnt,mg,mg_cnt;
int a[N],
	sorted[N],
	_count[N],
	hash[N];
struct Data{
	int x,f;
}dp[105][105];
set<int> _set[N];
map<pair<int,int>,int> val;
int f(int i,int x){
	int ret;
	set<int>::iterator it=_set[x].lower_bound(i);
	if(it==_set[x].end())
		return val[mp(x,*(--it))];
	int tmp=*it;
	if(i==tmp)
		return val[mp(x,tmp)];
	else
		return val[mp(x,tmp)]-1;
}
void predo(){
	sort(sorted,sorted+n);
	cnt=unique(sorted,sorted+n)-sorted;
	for(int i=0;i<n;++i){
		a[i]=lower_bound(sorted,sorted+cnt,a[i])-sorted;
		//cout<<a[i]<<' ';
	}
	//cout<<endl;
	memset(_count,0,sizeof(_count));
	val.clear();
	for(int i=0;i<n;++i){
		_set[i].clear();
	}
	for(int i=0;i<n;++i){
		val[mp(a[i],i)]=++_count[a[i]];
		_set[a[i]].insert(i);
	}

	memset(dp,0,sizeof(dp));
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
			//cout<<'s'<<sorted[a[i]]<<endl;
			++hash[a[i]];
			int oth=f(you,a[i])-f(zuo-1,a[i]);
			int sum=hash[a[i]]+oth;
			//cout<<zuo<<' '<<you<<' '<<oth<<endl;
			//cout<<"sum"<<sum<<endl;
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
			//cout<<'b'<<sorted[a[i]]<<endl;
			int oth=f(you,a[i])-f(zuo-1,a[i]);
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
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		sorted[i]=a[i];
	}
	predo();
	int l,r;
	for(int i=0;i<m;++i){
		scanf("%d%d",&l,&r);
		l=(l+ans-1)%n+1;
		r=(r+ans-1)%n+1;
		if(l>r) swap(l,r);
		ans=query(l,r);
		printf("%d\n",ans);
		//cout<<endl;
	}
	/*int i,x;
	while(cin>>i>>x){
		cout<<f(i,x)<<endl;
	}*/
	return 0;
}
