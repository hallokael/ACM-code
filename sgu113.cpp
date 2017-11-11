//水题 未过 谜之PE
//CV多个网络代码，一起PE
//半年后重交，过了
/********************************************************************
*   created:	7:11:2015   19:09
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

bool prime(int x)
{
 for (int i = 2; i <= sqrt( x*1.0 ); i++)
  if (x%i == 0)
   return false;
 return true;
}
bool isNearlyPrimeNum( int n )
{
 for(int i = 2 ; i <= sqrt( n ) ; i ++ )
  if( prime( i ) && n%i == 0 && prime( n / i ) )
   return true ;
 return false ;
}

int main()
{
 int n , num ;
 scanf( "%d" , &n ) ;
    while( n -- )
 {
  scanf( "%d" , &num ) ;
  if( isNearlyPrimeNum( num ) )
   printf( "Yes\n" );
  else
   printf( "No\n" );
 }
 return 0;
}