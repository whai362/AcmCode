import java.util.*;
class Main{
	static int[][] m=new int[205][205];
	static void gao(int x0,int y0,int n){
		int i,j,t1,t2,t3;
		if(n==0){
			m[x0][y0+2]=1;
			m[x0+1][y0+2]=1;
			for(i=0;i<5;++i){
				m[x0+2][y0+i]=1;
			}
			m[x0+3][y0+2]=1;
			m[x0+4][y0+2]=1;
		}
		else{
		t1=2*n+2;
		t2=4*n+5;
		for(i=0;i<t1;++i){
			if(i==0){
				t3=4*n+1;
				for(j=0;j<t3;++j){
					m[x0+i][y0+j+2]=1;
					m[x0+t2-i-1][y0+j+2]=1;
				}
			}
			else if(i==1){
				m[x0+i][y0+2]=1;
				m[x0+i][y0+t2-1-2]=1;
				m[x0+t2-i-1][y0+2]=1;
				m[x0+t2-i-1][y0+t2-1-2]=1;
			}
			else if(i==2){
				for(j=0;j<3;++j){
					m[x0+i][y0+j]=1;
					m[x0+i][y0+t2-j-1]=1;
					m[x0+t2-i-1][y0+j]=1;
					m[x0+t2-i-1][y0+t2-j-1]=1;
				}
			}
			else{
				m[x0+i][y0]=1;
				m[x0+i][y0+t2-1]=1;
				m[x0+t2-i-1][y0]=1;
				m[x0+t2-i-1][y0+t2-1]=1;
			}
		}
		m[x0+t1][y0]=1;
		m[x0+t1][y0+t2-1]=1;
		}
	}
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int i,j,n,t;
		n=in.nextInt();
		t=4*n+5;
		for(i=n;i>=0;--i){
			gao(2*(n-i),2*(n-i),i);
		}
		for(i=0;i<t;++i){
			for(j=0;j<t;++j){
				if(m[i][j]==1){
					System.out.print("$");
				}
				else
					System.out.print(".");
			}
			System.out.print("\n");
		}
	}
}
