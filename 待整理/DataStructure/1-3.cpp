#include<iostream>
#include<cstring>
using namespace std;
template <typename T,int SIZE>
class Array{
	private:
		T *data;
		int len;
	public:
		void overflow(){
			T *tmp=new T[len+1];
			memcpy(tmp,data,sizeof(T)*len);
			data=tmp;
			return ;
		}
		void insert(T num){
			data[len++]=num;
			return ;
		}
		void create(){
			T num;
			len=0;
			data=new T[SIZE];
			cout<<"输入顺序表数据(以-1结束): "<<endl;
			while(cin>>num && num!=-1)
				data[len++]=num;
			return ;
		}
		void print(){
			int i;
			cout<<"当前链表数据: "<<endl;
			for(i=0;i<len;++i){
				cout<<data[i]<<' ';
			}
			cout<<endl;
			return ;
		}
};
int main(){
	int num;
	Array<int,50> a;
	a.create();
	a.print();
	cout<<"输入插入数据: "<<endl;
	while(cin>>num){
		a.insert(num);
		a.print();
		cout<<"输入插入数据: "<<endl;
	}
	return 0;
}
