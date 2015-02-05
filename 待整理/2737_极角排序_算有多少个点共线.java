import java.util.*;
class Main{
	static double toAngle(double x,double y){
		double angle;
		if(y>0){
			if(x==0) return Math.PI/2;
			else if(x>0) return Math.atan(y/x);
			else return Math.PI+Math.atan(y/x);
		}
		else if(y==0){
			if(x>=0) return 0;
			else return Math.PI;
		}
		else{
			if(x==0) return 3*Math.PI/2;
			else if(x<0) return Math.PI+Math.atan(y/x);
			else return 2*Math.PI+Math.atan(y/x);
		}
	}
	static int Max(int a,int b){
		return a>b?a:b;
	}
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int ans=0,cas=0,cnt=0,i,j,n;
		while(true){
			n=in.nextInt();
			if(n==0) break;
			double[] t=new double[n-1];
			point[] p=new point[n];
			for(i=0;i<n;++i){
				p[i]=new point();
				p[i].x=in.nextDouble();
				p[i].y=in.nextDouble();
			}
			ans=0;
			for(i=0;i<n;++i){
				cnt=0;
				for(j=0;j<n;++j){
					if(i==j) continue;
					t[cnt++]=toAngle(p[j].x-p[i].x,p[j].y-p[i].y);
				}
				Arrays.sort(t);
				int _max=1,tmp=1;
				for(j=1;j<cnt;++j){
					if(t[j]==t[j-1]) ++tmp;
					else tmp=1;
					_max=Max(_max,tmp);
				}
				ans=Max(ans,_max);
			}
			if(ans+1>=4) System.out.println("Photo "+(++cas)+": "+(ans+1)+" points eliminated");
			else System.out.println("Photo "+(++cas)+": 0 points eliminated");
		}
	}
}
class point{
	double x,y;
}
