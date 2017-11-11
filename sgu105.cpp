//¹æÂÉ
/********************************************************************
*   created:	22:10:2015   12:38
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

int main()
{
 int n ;
 scanf( "%d" , &n ) ;
 int num = n / 3*2 ;
    if( n%3 != 0 )
        num += ( n%3 - 1 ) ;
 printf( "%d\n" , num );
 return 0;
}