#include<iostream>
#include<cstring>
using namespace std;
struct Data{
	int i,j,value;
};
struct Matrix{
	Data *data;
	int n,m,k;
};
int main(){
	int i,j;
	int **ans;
	Matrix m1,m2;
	cout<<"输入三元组行,列,元素个数:"<<endl;
	cin>>m1.n>>m1.m>>m1.k;
	m1.data=new Data[m1.k];
	cout<<"输入三元组:"<<endl;
	for(i=0;i<m1.k;++i){
		cin>>m1.data[i].i>>m1.data[i].j>>m1.data[i].value;
	}
	cout<<"输入三元组行,列,元素个数:"<<endl;
	cin>>m2.n>>m2.m>>m2.k;
	m2.data=new Data[m1.k];
	cout<<"输入三元组:"<<endl;
	for(i=0;i<m1.k;++i){
		cin>>m2.data[i].i>>m2.data[i].j>>m2.data[i].value;
	}
	if(m1.n==m2.n && m1.m==m2.m){
		ans=new int*[m1.n];
		for(i=0;i<m1.n;++i){
			ans[i]=new int[m1.m];
			for(j=0;j<m1.m;++j){
				ans[i][j]=0;
			}
		}
		for(i=0;i<m1.k;++i)
		  ans[m1.data[i].i-1][m1.data[i].j-1]+=m1.data[i].value;
		for(i=0;i<m2.k;++i)
		  ans[m2.data[i].i-1][m2.data[i].j-1]+=m2.data[i].value;
		cout<<"相加:"<<endl;
		for(i=0;i<m1.n;++i){
			for(j=0;j<m1.m;++j){
				cout<<ans[i][j]<<' ';
			}
			cout<<endl;
		}
	}
	else cout<<"无法相加"<<endl;
	return 0;
}
