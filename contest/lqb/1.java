import java.util.*;
class Main{
	public static final int M=10007,N=1000001;
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int n;
		int[] f=new int[N];
		f[0]=f[1]=1;
		for(int i=2;i<N;++i){
			f[i]=(f[i-1]+f[i-2])%M;
		}
		n=in.nextInt();
		System.out.println(f[n-1]);
	}
}
