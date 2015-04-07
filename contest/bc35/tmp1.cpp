#include<iostream>
#include<cstdio>
using namespace std;
template<typename T>
class Data{
	T data;
	Data<T>* next;
};
template<typename T>
class FreeList{
	private:
		Data<T*> head,tail;
	public:
		FreeList(){
			head=NULL;
			tail=NULL;
		}

		Data<T>* newData(){
			if(head==NULL){
				return new Data<T>();
			}
			else{
				return head;
				head=head->next;
				if(head==NULL)
					tail=NULL;
			}
		}
		void deleteData(Data<T>* data){
			if(head==NULL){
				head=tail=data;
				data->next=NULL;
			}
			else{
				tail->next=data;
				tail=data;
				tail->next=NULL;
			}
		}
};
int main(){
	//Data<int*> data;
	FreeList<int> free_list;
}
