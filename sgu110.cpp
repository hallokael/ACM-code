//没有模板+默写题解
//几何模板题

#include <iostream>
#include <cmath>
using namespace std;

#define ZERO 1e-10

inline double sqr(double x){return x*x;}
inline double min(double x1, double x2){return x1>x2 ? x2:x1;}

typedef struct _vector3f
{
 double x;
 double y;
 double z;
 _vector3f(){};
 _vector3f(double _x, double _y, double _z){x = _x;y = _y;z = _z;}
} vector3f;

typedef struct _sphere
{
 double x;
 double y;
 double z;
 double r;
 _sphere(){};
 _sphere(double _x, double _y, double _z, double _r){x = _x;y = _y;z = _z;r = _r;}
} Sphere;

/*
* -1 means no root
*  1 means we have root
*/
int calIntersaction(vector3f start, vector3f direction, Sphere sphere, double &t)
{
 double a = sqr(direction.x) + sqr(direction.y) + sqr(direction.z);

 double t1 = start.x - sphere.x;
 double t2 = start.y - sphere.y;
 double t3 = start.z - sphere.z;

 double b = 2.0 * (t1*direction.x + t2*direction.y + t3*direction.z);
 double c = sqr(t1) + sqr(t2) + sqr(t3) - sqr(sphere.r);

 double delta = sqr(b) - 4.0*a*c;
 //cout << "delta = " << delta << endl;
 if(delta < -ZERO)
  return -1;
 double root1 = ((-1.0 * b) + sqrt(delta)) / (2.0 * a);
 double root2 = ((-1.0 * b) - sqrt(delta)) / (2.0 * a);
 if(root1 < -ZERO)
  return -1;

 t = min(root1, root2);
 return 1;
}

/*
* center is the center of sphere
* p is the intersection
* incident is the incident ray
*/
vector3f calRefVector(Sphere center, vector3f p, vector3f start)
{
 vector3f normal = vector3f(p.x-center.x, p.y-center.y, p.z-center.z);

 //vector n1 = (p.x+t*n.x-p1.x, p.y+t*n.y-p1.y, p.z+t*n.z-p1.z)
 //vector n2 = normal
 // n1*n2 = 0
 double dx = p.x-start.x;
 double dy = p.y-start.y;
 double dz = p.z-start.z;

 double right = dx*normal.x + dy*normal.y + dz*normal.z;
 double left = sqr(normal.x) + sqr(normal.y) + sqr(normal.z);
 double t = -1.0*right/left;

 vector3f middle = vector3f(p.x+t*normal.x, p.y+t*normal.y, p.z+t*normal.z);
 vector3f anotherPoint = vector3f(2.0*middle.x-start.x, 2.0*middle.y-start.y, 2.0*middle.z-start.z);
 return vector3f(anotherPoint.x-p.x, anotherPoint.y-p.y, anotherPoint.z-p.z);
}
int main()
{
 double x , y , z , r ;
 int n ;
 cin >> n ;
 Sphere sph[50] ;
 for(int j = 0 ; j < n ; j ++ )
 {
  cin >> x >> y >> z >> r ;
  sph[j] = Sphere( x , y , z , r ) ;
 }
 cin >> x >> y >> z ;
 vector3f start = vector3f( x , y , z ) ;
 cin >> x >> y >> z ;
 vector3f direct = vector3f( x - start.x , y - start.y , z - start.z ) ;
 int last =  - 1 ;
 for(int i = 0 ; i < 11 ; i ++ )
 {
  double m = 1e200 ;
  int ref =  - 1 ;
  for(int k = 0 ; k < n ; k ++ )
  {
   double t ;
   int res = calIntersaction( start , direct , sph[k] , t ) ;
   if( res !=  - 1 && last != k && t < m )
   {
    m = t ;
    ref = k ;
   }
  }
  last = ref ;
  if( ref ==  - 1 )
   break;
  if( i == 10 )
  {
   cout << "etc." ;
   break;
  }
  cout << ref + 1 << " " ;
  vector3f ins =     vector3f( start.x + m*direct.x , start.y + m*direct.y , start.z + m*direct.z ) ;
  direct = calRefVector( sph[ref] , ins , start ) ;
  start.x = ins.x ;
  start.y = ins.y ;
  start.z = ins.z ;
 }
 cout << endl ;
 return 0;
}
