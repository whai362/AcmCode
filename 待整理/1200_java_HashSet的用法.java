//题意：
//求一个字符串str的所有长度为n的子串，其中原串的不同字符个数为nc，这个题用枚举找出所有的子串，遍历即可，但是需要判重，例如:
import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		Set<String> h=new HashSet<String>();
		int i,n,nc,len;
		String s,tmp;
		n=in.nextInt();
		nc=in.nextInt();
		s=in.next();
		len=s.length();
		for(i=0;i<=len-n;++i){
			tmp=s.substring(i,i+n);
			h.add(tmp);
		}
        System.out.println(h.size());
		/*Iterator it=h.iterator();	//无序输出
        while(it.hasNext()){
            System.out.println(it.next());
        }*/
	}
}
