import java.util.*;

public class PowerfulSpell
{
   public static void main(String[] arg) throws java.io.IOException
   {
      // データセットを１個読み込んでは solve() を呼び出すループ
      for(Scanner sc = new Scanner(System.in) ;;)
      {
         int N = sc.nextInt();
         int A = sc.nextInt();
         int S = sc.nextInt();
         int G = sc.nextInt();
         if( N==0 && A==0 && S==0 && G==0 )
            break;

         Arrow[] arr = new Arrow[A];
         for(int i=0; i<A; ++i)
            arr[i] = new Arrow(sc);

         System.out.println( solve(N,S,G,arr) );
      }
   }

   // 矢印データ
   static class Arrow
   {
      final int    x;
      final int    y;
      final String lab;

      Arrow(Scanner sc) throws java.io.IOException
      {
         x   = sc.nextInt();
         y   = sc.nextInt();
         lab = sc.next();
      }
   }

   // スタートからの経路を表すデータ
   // どういう文字列で来たか（spell）と、今どの節点にいるか（lastNode）
   static class Path implements Comparable<Path>
   {
      final String spell;
      final int lastNode;
      Path(String s, int n) { spell=s; lastNode=n; }

      // 辞書順で早いほうが「良い」経路
      public int compareTo( Path rhs ) {
         int c = spell.compareTo(rhs.spell);
         return c!=0 ? c : lastNode-rhs.lastNode;
      }
   }

   // 本体
   static String solve(int N, int S, int G, Arrow[] arr)
   {
      // とりあえず、ゴールに着けない節点に迷い込んではいけないので、
      // まず全節点について、ゴールまで行けるかどうか調べておく
      //
      // 方法は、幅優先探索(BFS)でも深さ優先探索(DFS)でも、
      // なんでもお好みの方法でいいと思います。

      boolean[][] reachable = new boolean[N][N];

      for(Arrow a : arr)
         reachable[a.x][a.y] = true;
      for(int k=0; k<N; ++k)
      {
         reachable[k][k] = true;
         for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
               reachable[i][j] |= reachable[i][k] & reachable[k][j];
      }

      // そもそもスタートからゴールに行けない場合は "NO"

      if( !reachable[S][G] )
         return "NO";

      // 行ける場合は、
      // スタートから始めて、「辞書順で早い順に」経路文字列を全探索していきます。

      TreeSet<Path> q = new TreeSet<Path>(); // 探索候補
      q.add( new Path("",S) ); // 「スタート S にいます」状態から探索開始

      for(;;)
      {
         Path p = q.pollFirst(); // 候補のなかから一番早いのを取り出す

         if( p.lastNode == G ) // ゴールについた
            return p.spell;

         if( p.spell.length() >= N*6 ) // ループしてる
            return "NO";

         for(Arrow a : arr) // それ以外：今の節点から一つパス延ばしたものを候補に入れる
            if( p.lastNode==a.x && reachable[a.y][G] )
               q.add( new Path(p.spell+a.lab, a.y) );
          // 本当は、"辞書順で最小の矢印と、それを接頭辞とするもの" だけ
          // 入れれば十分なんですが、コード書くの面倒なので全部入り…
      }
   }
}
