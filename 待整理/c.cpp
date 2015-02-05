#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;
vector<int> e,o,ve[N],vo[N];
int cnte,cnto,pe,po;
int main(){
	int a,n,k,p,flag=1;
	int i,j;
	scanf("%d%d%d",&n,&k,&p);
	for(i=0;i<n;++i){
		scanf("%d",&a);
		if(a%2) o.push_back(a);
		else e.push_back(a);
	}
	if(k!=p){
		cnte=cnto=pe=po=0;
		if(e.size()>=p){
			cnte=p;
			for(i=0;i<p;++i){
				ve[i].push_back(e[i]);
			}
			pe=p;
		}
		else{
			int sz=e.size();
			cnte=sz;
			for(i=0;i<sz;++i){
				ve[i].push_back(e[i]);
			}
			pe=sz;
		}
		if(cnte<p){
			int sz=o.size();
			if(sz/2<p-cnte){
				flag=0;
			}
			else{
				for(i=cnte;i<p;++i){
					ve[i].push_back(o[po++]);
					ve[i].push_back(o[po++]);
				}
				cnte=p;
			}
		}
		for(i=pe;i<e.size();++i){
			vo[0].push_back(e[i]);
		}
		if(o.size()-po<k-p){
			flag=0;
		}
		else{
			for(i=po;i<po+k-p;++i){
				vo[cnto++].push_back(o[i]);
			}
			int tmp=o.size()-(po+k-p);
			if(tmp%2){
				flag=0;
				/*for(i=po+k-p;i<o.size();++i){
				//vo[0].push_back(o[i]);
				}*/
			}
			else{
				for(i=po+k-p;i<o.size();++i){
					vo[0].push_back(o[i]);
				}
			}
		}
	}
	if(k==p){
		cnte=cnto=pe=po=0;
		if(e.size()>=p){
			cnte=p;
			for(i=0;i<p;++i){
				ve[i].push_back(e[i]);
			}
			pe=p;
		}
		else{
			int sz=e.size();
			cnte=sz;
			for(i=0;i<sz;++i){
				ve[i].push_back(e[i]);
			}
			pe=sz;
		}
		if(cnte<p){
			int sz=o.size();
			if(sz/2<p-cnte){
				flag=0;
			}
			else{
				for(i=cnte;i<p;++i){
					ve[i].push_back(o[po++]);
					ve[i].push_back(o[po++]);
				}
				cnte=p;
			}
		}
		for(i=pe;i<e.size();++i){
			ve[0].push_back(e[i]);
		}
		if(o.size()-po<k-p){
			flag=0;
		}
		else{
			for(i=po;i<po+k-p;++i){
				vo[cnto++].push_back(o[i]);
			}
			int tmp=o.size()-(po+k-p);
			if(tmp%2){
				flag=0;
			}
			else{
				for(i=po+k-p;i<o.size();++i){
					ve[0].push_back(o[i]);
				}
			}
		}	
	}
	if(flag){
		printf("YES\n");
		for(i=0;i<p;++i){
			int sz=ve[i].size();
			printf("%d",sz);
			for(j=0;j<sz;++j){
				printf(" %d",ve[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<k-p;++i){
			int sz=vo[i].size();
			printf("%d",sz);
			for(j=0;j<sz;++j){
				printf(" %d",vo[i][j]);
			}
			printf("\n");
		}
	}
	else
	  printf("NO\n");
	return 0;
}
