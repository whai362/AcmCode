#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<tr1/unordered_map>
#include<algorithm>
using namespace std;
using namespace std::tr1;
#define PB push_back
const int N=100005;
struct Dt{
	string name;
	vector<int> inf;
}a[N];
int fa[N];
int getFa(int x){
	if(x!=fa[x]) return fa[x]=getFa(fa[x]);
	return x;
}

unordered_map<string,int> id_pool;
int tot;
void init(int n){
	for(int i=0;i<n;++i){
		fa[i]=i;
	}
	id_pool.clear();
	for(int i=0;i<tot;++i){
		a[i].inf.clear();
	}
	tot=1;
}
int main(){
	int n;
	ios::sync_with_stdio(false);
	while(cin>>n){
		init(n);
		string op;
		for(int i=0;i<n;++i){
			cin>>op;
			if(op[0]=='a'){
				cin>>a[tot].name;
				id_pool[a[tot].name]=tot;
				int m;
				cin>>m;
				int inf;
				for(int i=0;i<m;++i){
					cin>>inf;
					a[tot].inf.PB(inf);
					sort(a[tot].inf.begin(),a[tot].inf.end());
				}
				++tot;
			}
			else if(op[0]=='s'){
				string name1,name2;
				cin>>name1>>name2;
				
				int fx=getFa(id_pool[name1]);
				int fy=getFa(id_pool[name2]);
				if(fx==fy) continue;
				vector<int> tmp;
				//cout<<fx<<' '<<fy<<endl;
				set_union(a[fx].inf.begin(), a[fx].inf.end(),
						a[fy].inf.begin(), a[fy].inf.end(),
						inserter(tmp,tmp.begin()));
				a[fx].inf=tmp;
				fa[fy]=fx;
			}
			else{
				string name;
				cin>>name;
				int fx=getFa(id_pool[name]);
				//cout<<'!'<<fx<<endl;
				cout<<a[fx].inf.size()<<endl;
				//for(int i=0;i<a[fx].inf.size();++i){
				//	cout<<a[fx].inf[i]<<' ';
				//}
				//cout<<endl;
			}
		}
	}
	return 0;
}
