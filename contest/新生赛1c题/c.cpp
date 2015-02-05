#include<stdio.h>
int heap[100010],size;
void swim(int p){
    int q=p>>1,tmp=heap[p];
    while(q&&tmp<heap[q]){ heap[p]=heap[q]; p=q; q=p>>1; }
    heap[p]=tmp;
}
void sink(int p){
    int q=p<<1,tmp=heap[p];
    while(q<=size){
        if(q<size&&heap[q+1]<heap[q]) q++;
        if(heap[q]>=tmp) break;
        heap[p]=heap[q]; p=q; q=p<<1;
    }
    heap[p]=tmp;
}
void insert(int num){
	heap[++size]=num;
	swim(size); 
}
void del(int num){
	int i;
	for(i=1;i<=size;++i) if(num==heap[i]) break;
	heap[i]=heap[size];
	--size;
	swim(i);	//这里wa了n次，数据见下
	sink(i);
}

int main(){
	int i,j,k=2,n,m,num;
	char str[100];
	while(scanf("%d%d",&n,&m)!=EOF){
		size=0;
		for(i=0;i<n;++i){
			scanf("%d",&num);
			insert(num);
		}
		for(i=0;i<m;++i){
			k=2;
			scanf("%s%d",str,&num);
			if(str[0]=='a') insert(num);
			else del(num);
			for(j=1;j<=size;++j){
				if(j==k){
					printf("\n");
					k=k<<1;
				}
				printf("%d",heap[j]);
				if(j!=k-1&&j!=size) printf(" ");
			}
			printf("\n\n");
		}
	}
	return 0;
}
//			1
//		   / \
//		  7   2
//		 / \ / \
//		 8 9 3 4
//
//		 delete 8之后应是
//			1
//		   / \
//		  4   2
//		 / \ /
//		 7 9 3
//
//		 而不是
//			1
//		   / \
//		  7   2
//		 / \ /
//		 4 9 3
