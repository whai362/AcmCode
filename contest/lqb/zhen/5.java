import java.util.*;
class Main {
	static int[] a=new int[10005],hash=new int[10005];
	public static void main(String[] args){
		String tmp;
		Scanner in=new Scanner(System.in);
		int ans_n=0,ans_m=0,i,j,_min,_max,n;
		char[] str=new char[10005]; 
		n=in.nextInt();
		in.nextLine();
		_max=0;
		_min=0x3f3f3f3f;
		for(i=0;i<n;++i){
			int len,sum;
			tmp=in.nextLine();
			//System.out.println(tmp);
			//in.nextLine();
			str=tmp.toCharArray();
			len=tmp.length();
			sum=0;
			for(j=0;j<len;++j){
				if(str[j]>='0' && str[j]<='9'){
					sum=sum*10+str[j]-'0';
				}
				else{
					if(sum!=0){
						if(hash[sum]==0) hash[sum]=1;
						else ans_n=sum;
						if(sum>_max) _max=sum;
						if(sum<_min) _min=sum;
					}
					sum=0;
				}
			}
			if(sum!=0){
				if(hash[sum]==0) hash[sum]=1;
				else ans_n=sum;
				if(sum>_max) _max=sum;
				if(sum<_min) _min=sum;
			}
		}
		for(i=_min;i<=_max;++i){
			if(hash[i]==0){
				ans_m=i;
				break;
			}
		}
		System.out.println(ans_m+" "+ans_n);
	}
}
