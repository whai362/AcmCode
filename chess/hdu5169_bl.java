/*题意：
  小A和小B在玩一个游戏，他们一开始每人手上都有一个01字符串，其中记小A手上的为A串，小B手上的为B串。
  现在有一枚均匀的硬币，以及一个空字符串S，游戏开始后每一回合都会投掷这枚硬币，如果正面向上，就在S后面添加一个字符'1'，否则添加一个字符'0'。
  一旦某一回合结束时A串成为了S的子串，小A就赢了，同样如果B串成为了S的子串，小B就赢了，有一个人获得胜利时游戏结束。为了避免两个人同时胜利的情况，保证A不为B的后缀，B也不为A的后缀。
  在已知A和B的情况下，这个游戏是不是公平的呢，公平意味着小A与小B拥有相同的胜率，若不公平谁更有可能赢？
  限制：
  1 <= |A|,|B| <= 100
  思路：
  1. 首先要知道Penney’s game的结论：
  假如 a 和 b 是两个 n 位 01 串。如果 a 和 b 完全相等，那么记一个数字 1 ，如果不相等，那么记一个数字 0 。接下来，比较 a 的后面 n – 1 位以及 b 的前面 n – 1 位，如果相等，那么接着记一个数字 1 ，如果不相等，那么接着记一个数字 0 。接下来，比较 a 的后 n – 2 位以及 b 的前 n – 2 位，并根据比较结果记下数字 0 或者数字 1 。不断这样做下去，直到最后比较 a 的最后面 1 位和 b 的最前面 1 位，并产生新的数字。在整个过程中，你会依次记下 n 个数字，最终会得到一个 n 位的 01 串。把它当作一个二进制数，并转换成十进制。我们把最终的结果记为 L(a, b) 。举几个例子：
  L(10110, 10110) = (10010)2 = 18
  L(10110, 01011) = (00001)2 = 1
  L(01011, 01011) = (10000)2 = 16
  L(01011, 10110) = (01001)2 = 9
  那么， 01 串 a 和 b 的胜率之比就是
  (L(b, b) – L(b, a)) : (L(a, a) – L(a, b))

  2. 因为数据量小，只有100，可以直接用java大数暴力。
 */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static final int N = 105;
    static boolean cmp(char[] a,char[] b,int len){
        if(len>b.length) return false;
        boolean ret=true;
        for(int i=0;i<len;++i){
            if(b[i]!=a[a.length-len+i]){
                ret=false;
                break;
            }
        }
        return ret;
    }
    static BigInteger toBigInt(char a[],int len){
        BigInteger ret=BigInteger.ZERO;
        for(int i=len-1;i>=0;--i)
            ret=ret.multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(a[i]-'0'));
        return ret;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str;
        char[] A=new char[N];
        char[] B=new char[N];
        char[] aa=new char[N],bb=new char[N],
        ab=new char[N],ba=new char[N];
        BigInteger AA,BB,AB,BA;
        int ans;
        int T;
        T=in.nextInt();
        while(T-->0){
            str=in.next();
            A=str.toCharArray();
            str=in.next();
            B=str.toCharArray();
            for(int i=0;i<A.length;++i){
                if(cmp(A, A, i+1)) aa[i]='1';
                else aa[i]='0';
                if(cmp(A, B, i+1)) ab[i]='1';
                else ab[i]='0';
            }
            for(int i=0;i<B.length;++i){
                if(cmp(B, B, i+1)) bb[i]='1';
                else bb[i]='0';
                if(cmp(B, A, i+1)) ba[i]='1';
                else ba[i]='0';
            }
            AA=toBigInt(aa,A.length);
            BB=toBigInt(bb,B.length);
            AB=toBigInt(ab,A.length);
            BA=toBigInt(ba,B.length);
            /*System.out.println(AA);
            System.out.println(AB);
            System.out.println(BB);
            System.out.println(BA);*/
            ans=BB.subtract(BA).compareTo(AA.subtract(AB));
            if(ans==0) System.out.println("Fair");
            else if(ans>0) System.out.println("A");
            else System.out.println("B");
        }
    }
}
/*
1
10110
01011
*/
