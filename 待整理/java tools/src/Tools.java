import java.util.*;
import java.util.Collections;
class Tools{
	public static void main(String[] args){
		//输入输出
		/*Scanner in=new Scanner(System.in);
		String str1;
		str1=in.next();
		in.nextLine();	//为了方便使用nextLine()
		System.out.print(str1+"\n");
		
		String str2;
		str2=in.nextLine();
		System.out.print(str2+"\n");
		
		int num1;
		num1=in.nextInt();
		in.nextLine();
		System.out.print(num1+"\n");
		System.out.printf("%d\n",num1);
		
		double num2;
		num2=in.nextDouble();
		in.nextLine();
		System.out.print(num2+"\n");
		System.out.printf("%.2f\n",num2);*/
		
		//字符串
		/*String str1="Hello world!";
		//截取字符串
		String str2=str1.substring(0,3);	//0<=i<3
		System.out.print(str2+"\n");
		//字符串拼接
		str2=str1+"yes";
		System.out.print(str2+"\n");
		//替换字符串
		str2=str1.replace("Hel","hehe");
		System.out.print(str2+"\n");
		//将第三位替换成'k'
		str2=str1.substring(0,3)+"k"+str1.substring(4,str1.length());
		System.out.print(str2+"\n");
		//去除首尾空格
		str2="   hehe   ".trim();
		System.out.print(str2+"\n");
		//转换为小写
		str2="ASASFSD".toLowerCase();
		System.out.print(str2+"\n");
		//转换为大写
		str2=str2.toUpperCase();
		System.out.print(str2+"\n");
		//截取一个字符
		char ch=str1.charAt(0);
		System.out.print(ch+"\n");
		//bytes
		byte[] b=str1.getBytes();
		System.out.print(b+"\n");
		for(int i=0;i<b.length;++i){
			System.out.print(b[i]+" ");
		}
		System.out.print("\n");
		//字符串转字符数组
		char[] str3=str1.toCharArray();
		System.out.print(str3.toString()+"\n");
		for(int i=0;i<str3.length;++i){
			System.out.print(str3[i]+" ");
		}
		System.out.print("\n");
		//字符串比较函数
		if(!str1.equals("111")){
			System.out.print("不一样\n");
		}
		if(str1.compareTo("AAA")>0){
			System.out.print("比***大\n");	//<0 ==0
		}
		//是否以特定字符开始  
        if(str1.startsWith("Hello")){
        	System.out.print("以Hello开头\n");  
        }
        //是否以特定字符结尾  
        if(str1.endsWith("world!")){
        	System.out.print("以world!结尾\n");  
        }
		//查找字符串出现位置
        int pos=str1.indexOf("wor");
        System.out.print(pos+"\n");	//只查出现的第一个位置
        //检查字符串是否为空 null和 ""
        str2="";
        if(str2.isEmpty()){
        	System.out.print("空\n");
        }*/
		
		//排序
		//整数排序
		Scanner in=new Scanner(System.in);
		Integer[] a=new Integer[10];
		for(int i=0;i<a.length;++i){
			a[i]=in.nextInt();
		}
		Arrays.sort(a);	//只对Object有效
		for(int i=0;i<a.length;++i){
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		Arrays.sort(a,Collections.reverseOrder());
		for(int i=0;i<a.length;++i){
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		//结构体排序
		Scanner in=new Scanner(System.in);
		Data[] a=new Data[10];
		for(int i=0;i<a.length;++i){
			a[i]=new Data();
			a[i].a=in.nextInt();
			a[i].b=i;
		}
		Comparator<Data> cmp=new Comparator<Data>(){	//方法一
			public int compare(Data a,Data b){
				return a.a-b.a;
			}
		};
		Arrays.sort(a,cmp);	//只对Object有效
		for(int i=0;i<a.length;++i){
			System.out.print(a[i].a+" ");
		}
		System.out.print("\n");
		//浮点型排序
		Double[] a={1.1,1.2,2.4,1.9,10.1,5.5,4.4};
		Arrays.sort(a);
		for(int i=0;i<a.length;++i){
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		Arrays.sort(a,Collections.reverseOrder());
		for(int i=0;i<a.length;++i){
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		
		//其他小工具
		/*List tmp,list=new ArrayList();
		Integer[] a={1,2,3,4,5};
		for(int i=0; i<a.length;++i)
			list.add(new Integer(a[i]));
		System.out.print(Collections.min(list)+"\n");
		System.out.print(Collections.max(list)+"\n");
		//Collections.copy(tmp,list);*/
		
		//队列
		/*Queue<Integer> q=new LinkedList<Integer>();
		for(int i=0;i<10;++i){
			q.offer(i);	//入队
		}
		System.out.println(q.peek()); //队头
		while(!q.isEmpty()){
			System.out.println(q.poll());	//出队
		}*/
		
		//优先队列
		/*PriorityQueue<Integer> pq=new PriorityQueue<Integer>();
		pq.add(5);
		pq.add(4);
		pq.add(8);
		pq.add(10);
		while(!pq.isEmpty()){
			System.out.println(pq.poll());
		}*/
		Comparator<Integer> cmp=new Comparator<Integer>(){	//方法一
			public int compare(Integer a,Integer b){
				return b-a;
			}
		};
		PriorityQueue<Integer> pq=new PriorityQueue<Integer>(10000000,cmp);
		pq.add(5);
		pq.add(4);
		pq.add(8);
		pq.add(10);
		while(!pq.isEmpty()){
			System.out.println(pq.poll());
		}
	}
}
class Data{
	int a,b;
}
/*class Mycomparator implements Comparator{	//方法二
	public int compare(Object o1,Object o2){
		Data a=(Data)o1;
		Data b=(Data)o2;
		return	a.a-b.a;//降序
		//a<b return -1;
		//a==b return 0;
		//a>b return 1;
	}
}*/
