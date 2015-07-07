#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct Data{
	string s;
	int number;
};
/*int cmp(const sort *a,const sort *b){
  return(a->number-b->number);
  }*/
bool cmp(Data a,Data b){
	return a.number<b.number;
}

Data inv[105];
int main(){	
	int m,n;
	cin>>m>>n;
	//cout<<sizeof(inv)/(sizeof(sort))<<endl;
	for(int i=0;i<n;i++){
		cin>>inv[i].s;
		inv[i].number=0;
		for(int j=0;j<m;j++)
			for(int k=j+1;k<m;k++)
				if(inv[i].s[j]>inv[i].s[k])
					inv[i].number++;
	} 
	//qsort(inv,n,sizeof(sort),(int(*)(const void*,const void*))cmp);
	sort(inv,inv+n,cmp);
	for(int i=0;i<n;i++)
		cout<<inv[i].s<<endl;
	return 0;
}

