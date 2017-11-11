//第一次写滚动数组，水题
/********************************************************************
*   created:	22:10:2015   21:45
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
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define ll long long
int dd( int num )
{
 int sum = num ;
 while( num )
 {
  sum += ( num%10 ) ;
  num /= 10 ;
 }
 return sum ;
}
int G[201] ;
void cl()
{
 for(int i = 1 ; i <= 100 ; i ++ )
 {
  G[i] = G[i + 100] ;
  G[i + 100] = 0 ;
 }
}
int basenum ;
int ans[1000005] ;
int main()
{
 int n , k ;
 scanf( "%d%d" , &n , &k ) ;
 int m = n / 100 ;
 int e = 1 ;
 for(int i = 0 ; i < m ; i ++ )
 {
  cl() ;
  basenum = i*100 ;
  for(int j = 1 ; j <= 100 ; j ++ )
  {
   int an = dd( j + basenum ) ;
   G[an - basenum] ++ ;
  }
  for(int j = 1 ; j <= 100 ; j ++ )
  {
   if( !G[j] && j + basenum > ans[e - 1] )
    ans[e ++] = j + basenum ;
  }
 }
 cl() ;
 basenum = m*100 ;
 for(int i = 1 ; i <= 100 ; i ++ )
 {
  int an = dd( i + basenum ) ;
  G[an - basenum]++ ;
 }
 for(int i = 1 ; i <= 100 ; i ++ )
 {
  if( !G[i] && i + basenum > ans[e - 1] )
   ans[e ++] = i + basenum ;
 }
 int b ;
 for(int i = 1 ; i <= n ; i ++ )
 {
  if( ans[i] > n )
  {
   e = i ;
   break ;
  }
 }
 printf( "%d\n" , e - 1 );
 for(int i = 0 ; i < k ; i ++ )
 {
  scanf( "%d" , &b ) ;
  printf( "%d" , ans[b] );
  if( i != k - 1 )
   printf( " " );
 }
 printf( "\n" );
 return 0;
}