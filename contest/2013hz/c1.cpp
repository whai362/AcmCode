#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[40][40],b[40][40],c[40][40];
int n;
void work(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			c[i][j]=a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			a[n-j+1][i]=c[i][j];
		}
	}
	//cout<<endl;	
	//for (int i=1;i<=n;i++){
	//	for (int j=1;j<=n;j++){
	//		cout<<c[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}
}

int main(){
	while (scanf("%d",&n),n){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				scanf("%d",&b[i][j]);
			}
		}
		int ans=0;
		for (int k=0;k<4;k++){
			int sum=0;
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					if (a[i][j]==b[i][j]) sum++;
				}
			}
			//for (int i=1;i<=n;i++){
			//	for (int j=1;j<=n;j++){
			//		cout<<a[i][j]<<' ';
			//	}
			//	cout<<endl;
			//}
			if (sum>ans) ans=sum;
			work();
		}
		printf("%d\n",ans);
	}
	return 0;
}
