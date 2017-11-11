//不断删除角上的一斜排，第一次要删的尽量多才能K<300
//看漏了很多条件，极限数据是要测试的
/********************************************************************
*   created:	23:10:2015   12:01
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
int n ;
int ok( int i , int j )
{
 if( i <= n && i >= 1 && j <= n && j >= 1 )
  return 1 ;
 return 0 ;
}
void Print( int i )
{
 for(int j = 1 ; j <= n ; j ++ )
 {
  if( ok( i , j ) )
   printf( " %d" , n*( j - 1 ) + i );
  i -- ;
 }
 printf( "\n" );
}
int main()
{
 while( scanf( "%d" , &n ) != EOF )
 {
  int k = n ;
  int f = 0 ;
  for( int i = 2*n - 1 ; i > n + 1 ; i -- )
  {
   if( !f )
   {
    printf( "%d",k );
   }
   f = 1 ;
   int ii = i ;
   for(int j = 1 ; j <= n ; j ++ )
   {
    if( ok( ii , j ) )
     printf( " %d" , n*( j - 1 ) + ii );
    ii -- ;
   }
  }
  if( f )
   printf( "\n" );
  if( k%2 == 0 )
   k ++ ;
  else k += 2 ;
  int t = min( 2*n - 1 , n + 1 ) ;
  for(int i = n + 1 ; i >= 2 ; i -- )
  {
   printf( "%d",k );
   k+=2;
   Print( i ) ;
  }
 }
 return 0;
}