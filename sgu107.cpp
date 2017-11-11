//暴搜，然后排列组合
/********************************************************************
*   created:	22:10:2015   20:26
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

int main()
{
 int n ;
 scanf( "%d" , &n ) ;
 if( n < 9 )
 {
  printf( "0\n" );
  return 0 ;
 }
 else if( n == 9 )
 {
  printf( "8\n" );
  return 0 ;
 }
 else
 {
  printf( "72" );
  for( int i = 10 ; i < n ; i ++ )
  {
   printf( "0" );
  }
  printf( "\n" );
 }
 return 0;
}