//dp
/********************************************************************
*   created:	8:10:2015   20:34
*********************************************************************/
#include<string.h>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
int val[200][200] ;
int dp[200][200] ;
int f[205][205] ;
int main()
{
 int F , V ;
 scanf( "%d%d" , &F , &V ) ;
 memset( f ,  - 1 , sizeof( f ) ) ;
 for(int i = 1 ; i <= F ; i ++ )
 {
  for(int j = 1 ; j <= V ; j ++ )
  {
   scanf( "%d" , &val[i][j] ) ;
  }
 }
 for(int i = 1 ; i <= V ; i ++ )
  dp[1][i] = val[1][i] ;
 for(int i = 2 ; i <= F ; i ++ )
 {
  for(int j = 1 ; j <= V ; j ++ )
  {
   int ma =  - 1e7 ;
   for( int k = 1 ; k < j ; k ++ )
   {
    if( dp[i - 1][k] + val[i][j] > ma )
    {
     ma = dp[i - 1][k] + val[i][j] ;
     f[i][j] = k ;
    }
   }
   dp[i][j] = ma ;
  }
 }
 int ans =  - 1e7 ;
 int fi ;
 for(int i = 1 ; i <= V ; i ++ )
 {
  if( dp[F][i] > ans )
  {
   ans = dp[F][i] ;
   fi = i ;
  }
 }
 int an[200] ;
 int e = 0 ;
 while( fi >= 0 )
 {
  an[e ++] = fi ;
  fi = f[F --][fi] ;
 }
 printf( "%d\n" , ans );
 if( e == 0 )
 {
  printf( "%d\n" , fi ) ;
 }
 else
 {
  for( int i = e - 1 ; i >= 0 ; i -- )
  {
   printf( "%d" , an[i] );
   if( i )
    printf( " " );
   else
    printf( "\n" );
  }
 }
 return 0;
}