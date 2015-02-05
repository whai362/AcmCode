#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 1005
struct Array{
	int len;
	int *data;
};
void create(Array &a){
	int num;
	a.len=0;
	a.data=new int[SIZE];
	cout<<"输入顺序表数据(以-1结束): "<<endl;
	while(cin>>num && num!=-1){
		a.data[a.len++]=num;
	}
	return ;
}
void trans(Array &a){
	int i,*tmp=new int[a.len];
	for(i=a.len-1;i>=0;--i){
		tmp[a.len-1-i]=a.data[i];
	}
	a.data=tmp;
	return ;
}
void print(Array a){
	int i;
	for(i=0;i<a.len;++i){
		cout<<a.data[i]<<' ';
	}
	cout<<endl;
	return ;
}
int main(){
	int num;
	Array a;
	create(a);
	cout<<"原顺序表: "<<endl;
	print(a);
	trans(a);
	cout<<"转置后顺序表: "<<endl;
	print(a);
	return 0;
}

