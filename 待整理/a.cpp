#include<iostream>
#include<cstdio>
using namespace std;
int f[100][100];
int p[100];
int n;
void insert(int r, int x)
{
    for (int i=1; 1; i++)
        if (f[r][i]==0)
        {
            f[r][i]=x;
            return ;
        }
        else if (f[r][i]>x)
        {
            int tmp=f[r][i];
            f[r][i]=x;
            insert(r+1, tmp);
            return ;
        }
}
void print(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<f[i][j]<<' ';
		}
		cout<<endl;
	}
}
void Permutation2Matrix()
{

    for (int i=1; i<=n; i++){
        insert(1, p[i]);
		print();
		cout<<endl;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p[i];
	}
	Permutation2Matrix();
	return 0;
}
