#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 1005
struct Array{
	int len;
	int *data;
};
void overflow(Array &a){
	int *tmp=new int[a.len+1];
	memcpy(tmp,a.data,sizeof(int)*a.len);
	a.data=tmp;
	return ;
}
void insert(Array &a,int num){
	int i,left=-1,right=a.len,mid;
	while(left+1<right){
		mid=(left+right)>>1;
		if(a.data[mid]<num)
			left=mid;
		else right=mid;
	}
	if(a.len>=SIZE) overflow(a);
	for(i=a.len-1;i>=right;--i){
		a.data[i+1]=a.data[i];
	}
	++a.len;
	a.data[right]=num;
	return ;
}
void create(Array &a){
	int num;
	a.len=0;
	a.data=new int[SIZE];
	cout<<"输入顺序表数据(以-1结束): "<<endl;
	while(cin>>num && num!=-1)
		insert(a,num);
	return ;
}
void print(Array a){
	int i;
	cout<<"当前顺序表数据: "<<endl;
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
	print(a);
	cout<<"输入插入数据: "<<endl;
	while(cin>>num){
		insert(a,num);
		print(a);
		cout<<"输入插入数据: "<<endl;
	}
	return 0;
}
