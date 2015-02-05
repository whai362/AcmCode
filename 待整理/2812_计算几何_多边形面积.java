import java.util.*;
class Main{
	static double xmult(point p1,point p2){
		return p1.x*p2.y-p2.x*p1.y;
	}
	static double _fabs(double a){
		return a>0?a:-a;
	}
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int i,n;
		double v,s;
		n=in.nextInt();
		while(n>=3){
			s=0;
			point[] p=new point[n+5];
			for(i=0;i<n;++i){
				p[i]=new point();
				p[i].x=in.nextDouble();
				p[i].y=in.nextDouble();
			}
			v=in.nextDouble();
			p[n]=p[0];
			for(i=0;i<n;++i){
				s+=0.5*xmult(p[i],p[i+1]);
			}
			System.out.printf("BAR LENGTH: %.2f\n",v/_fabs(s));
			n=in.nextInt();
		}
	}
}
class point{
	double x,y;
}
