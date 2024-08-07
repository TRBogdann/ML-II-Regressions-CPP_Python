#include "math.hpp"
#include "cmath"
#include <cmath>
#include <cstddef>
#include <math.h>
#include <string>

namespace Math{


double degreesToRad(const double &x)
{
return x*(PI/180);
}


const double theoremeOfCosine(double l1,double l2, double angle)
{
  angle=degreesToRad(angle);
  return sqrt(l1*l1+l2*l2-2*cos(angle)*l1*l2);
}


const double polygonRfinder(double l,double angle)
{
angle=degreesToRad(angle);
return sqrt((l*l)/(2*(1-cos(angle))));

}

vec2f::vec2f():x(0.0f),y(0.0f){};
vec2f::vec2f(double _x,double _y):x(_x),y(_y){};

vec2f::~vec2f(){}

vec2f::vec2f(const vec2f& v):x(v.x),y(v.y){};
vec2f& vec2f::operator=(const vec2f &v)
{

x=v.x;
y=v.y;

return *this;

}

vec2f vec2f::operator+(const vec2f &v)
{
 return vec2f(x+v.x,y+v.y);
}

void vec2f::operator+=(const vec2f &v)
{
x+=v.x;
y+=v.y;


}

vec2f vec2f::operator-(const vec2f &v)
{
 return vec2f(x-v.x,y-v.y);

}

void vec2f::operator-=(const vec2f &v)
{
x-=v.x;
y-=v.y;


}


vec2f vec2f::operator*(const double& a)
{
 return vec2f(a*x,a*y);

}

void vec2f::operator*=(const double& a)
{
x*=a;
y*=a;
}

vec2f vec2f::operator/(const double& a)
{
 return vec2f(x/a,y/a);

}

void vec2f::operator/=(const double& a)
{
x/=a;
y/=a;
}

double vec2f::operator*(const vec2f &v)
{
return x*v.x+y*v.y;
}

/*
vec3f vec2f::to3DVector()
{
return vec3f(x,y,0.0f);
}
*/

bool vec2f::operator==(const vec2f &v)
{
  if((x==v.x) && (y==v.y))return true;
  return false;
}


 std::ostream& operator<<(std::ostream &os,const vec2f &v)
{
return os<<"( "<<v.x<<" , "<<v.y<<" )";
}

double vec2f::getMagnitude()
{
    return sqrt(x*x+y*y);
}

vec2f operator+(double number,vec2f &v)
{
    return vec2f(v.x+number,v.y);
}
vec2f operator-(double number,vec2f &v)
{
    return vec2f(number-v.x,-v.y);
}
vec2f operator*(double number,vec2f &v)
{
    return vec2f(v.x*number,v.y*number);
}

vec2d::vec2d():x(0.0f),y(0.0f){};
vec2d::vec2d(double _x,double _y):x(_x),y(_y){};

vec2d::~vec2d(){}

vec2d::vec2d(const vec2d& v):x(v.x),y(v.y){};
vec2d::vec2d(const vec2f& v):x(v.x),y(v.y){};

vec2d& vec2d::operator=(const vec2d &v)
{

x=v.x;
y=v.y;

return *this;

}

vec2d vec2d::operator+(const vec2d &v)
{
 return vec2d(x+v.x,y+v.y);
}

void vec2d::operator+=(const vec2d &v)
{
x+=v.x;
y+=v.y;


}

vec2d vec2d::operator-(const vec2d &v)
{
 return vec2d(x-v.x,y-v.y);

}

void vec2d::operator-=(const vec2d &v)
{
x-=v.x;
y-=v.y;


}


vec2d vec2d::operator*(const double& a)
{
 return vec2d(a*x,a*y);

}

void vec2d::operator*=(const double& a)
{
x*=a;
y*=a;
}

vec2d vec2d::operator/(const double& a)
{
 return vec2d(x/a,y/a);

}

void vec2d::operator/=(const double& a)
{
x/=a;
y/=a;
}

double vec2d::operator*(const vec2d &v)
{
return x*v.x+y*v.y;
}


bool vec2d::operator==(const vec2d &v)
{
  if((x==v.x) && (y==v.y))return true;
  return false;
}


 std::ostream& operator<<(std::ostream &os,const vec2d &v)
{
return os<<"( "<<v.x<<" , "<<v.y<<" )";
}

double vec2d::getMagnitude()
{
    return sqrt(x*x+y*y);
}

vec2d operator+(double number,vec2d &v)
{
    return vec2d(v.x+number,v.y);
}
vec2d operator-(double number,vec2d &v)
{
    return vec2d(number-v.x,-v.y);
}
vec2d operator*(double number,vec2d &v)
{
    return vec2d(v.x*number,v.y*number);
}




vec3f::vec3f():x(0.0f),y(0.0f),z(0.0f){};
vec3f::vec3f(double _x,double _y,double _z):x(_x),y(_y),z(_z){};

vec3f::~vec3f(){}

vec3f::vec3f(const vec3f& v):x(v.x),y(v.y),z(v.z){};
vec3f::vec3f(const vec2f& v):x(v.x),y(v.y),z(0.0f){};
vec3f& vec3f::operator=(const vec3f &v)
{

x=v.x;
y=v.y;
z=v.z;

return *this;

}

vec3f vec3f::operator+(const vec3f &v)
{
 return vec3f(x+v.x,y+v.y,z+v.z);

}

void vec3f::operator+=(const vec3f &v)
{
x+=v.x;
y+=v.y;
z+=v.z;


}


vec3f vec3f::operator-(const vec3f &v)
{
 return vec3f(x-v.x,y-v.y,z-v.z);

}

void vec3f::operator-=(const vec3f &v)
{
x-=v.x;
y-=v.y;
z-=v.z;

}

vec3f vec3f::operator*(const double& a)
const {
 return vec3f(a*x,a*y,a*z);

}

void vec3f::operator*=(const double& a)
{
x*=a;
y*=a;
z*=a;

}
vec3f vec3f::operator/(const double& a)
{
 return vec3f(x/a,y/a,z/a);

}

void vec3f::operator/=(const double& a)
{
x/=a;
y/=a;
z/=a;

}

double vec3f::operator*(const vec3f &v)
{
return x*v.x+y*v.y+z*v.z;
}

bool vec3f::operator==(const vec3f &v)
{
  if((x==v.x) && (y==v.y) && (z==v.z))return true;
  return false;
}

 std::ostream& operator<<(std::ostream &os,const vec3f &v)
{
return os<<"( "<<v.x<<" , "<<v.y<<" , "<<v.z<<" )";
}

double vec3f::getMagnitude()
{
    return sqrt(x*x+y*y+z*z);
}

vec3f operator+(double number,vec3f &v)
{
    return vec3f(number+v.x,v.y,v.z);
}
vec3f operator-(double number,vec3f &v)
{
    return vec3f(number-v.x,-v.y,-v.z);
}
vec3f operator*(double number,vec3f &v)
{
    return vec3f(number*v.x,number*v.y,number*v.z);
}

vec3d::vec3d():x(0.0f),y(0.0f),z(0.0f){};
vec3d::vec3d(double _x,double _y,double _z):x(_x),y(_y),z(_z){};

vec3d::~vec3d(){}


vec3d::vec3d(const vec3f& v):x(v.x),y(v.y),z(v.z){};
vec3d::vec3d(const vec2f& v):x(v.x),y(v.y),z(0.0f){};
vec3d::vec3d(const vec2d& v):x(v.x),y(v.y),z(0.0f){};
vec3d::vec3d(const vec3d& v):x(v.x),y(v.y),z(v.z){};

vec3d& vec3d::operator=(const vec3d &v)
{

x=v.x;
y=v.y;
z=v.z;

return *this;

}

vec3d vec3d::operator+(const vec3d &v)
{
 return vec3d(x+v.x,y+v.y,z+v.z);

}

void vec3d::operator+=(const vec3d &v)
{
x+=v.x;
y+=v.y;
z+=v.z;


}


vec3d vec3d::operator-(const vec3d &v)
{
 return vec3d(x-v.x,y-v.y,z-v.z);

}

void vec3d::operator-=(const vec3d &v)
{
x-=v.x;
y-=v.y;
z-=v.z;

}

vec3d vec3d::operator*(const double& a)
const {
 return vec3d(a*x,a*y,a*z);

}

void vec3d::operator*=(const double& a)
{
x*=a;
y*=a;
z*=a;

}
vec3d vec3d::operator/(const double& a)
{
 return vec3d(x/a,y/a,z/a);

}

void vec3d::operator/=(const double& a)
{
x/=a;
y/=a;
z/=a;

}

double vec3d::operator*(const vec3d &v)
{
return x*v.x+y*v.y+z*v.z;
}

bool vec3d::operator==(const vec3d &v)
{
  if((x==v.x) && (y==v.y) && (z==v.z))return true;
  return false;
}

 std::ostream& operator<<(std::ostream &os,const vec3d &v)
{
return os<<"( "<<v.x<<" , "<<v.y<<" , "<<v.z<<" )";
}

double vec3d::getMagnitude()
{
    return sqrt(x*x+y*y+z*z);
}

vec3d operator+(double number,vec3d &v)
{
    return vec3d(number+v.x,v.y,v.z);
}
vec3d operator-(double number,vec3d &v)
{
    return vec3d(number-v.x,-v.y,-v.z);
}
vec3d operator*(double number,vec3d &v)
{
    return vec3d(number*v.x,number*v.y,number*v.z);
}





vec4f::vec4f():x(0.0f),y(0.0f),z(0.0f){};
vec4f::vec4f(double _x,double _y,double _z,double _w):x(_x),y(_y),z(_z),w(_w){};

vec4f::~vec4f(){}

vec4f::vec4f(const vec2f& v):x(v.x),y(v.y),z(0.0f),w(0.0f){};
vec4f::vec4f(const vec3f& v):x(v.x),y(v.y),z(v.z),w(0.0f){};
vec4f::vec4f(const vec4f& v):x(v.x),y(v.y),z(v.z),w(v.w){};
vec4f& vec4f::operator=(const vec4f &v)
{

x=v.x;
y=v.y;
z=v.z;
w=v.w;
return *this;

}

vec4f vec4f::operator+(const vec4f &v)
{
 return vec4f(x+v.x,y+v.y,z+v.z,w+v.w);

}

void vec4f::operator+=(const vec4f &v)
{
x+=v.x;
y+=v.y;
z+=v.z;
w+=v.w;

}


vec4f vec4f::operator-(const vec4f &v)
{
 return vec4f(x-v.x,y-v.y,z-v.z,w-v.w);

}

void vec4f::operator-=(const vec4f &v)
{
x-=v.x;
y-=v.y;
z-=v.z;
w-=v.w;

}

vec4f vec4f::operator*(const double& a)
{
 return vec4f(a*x,a*y,a*z,a*w);

}

void vec4f::operator*=(const double& a)
{
x*=a;
y*=a;
z*=a;
w*=a;
}
vec4f vec4f::operator/(const double& a)
{
 return vec4f(x/a,y/a,z/a,w/a);
}

void vec4f::operator/=(const double& a)
{
x/=a;
y/=a;
z/=a;
w/=a;
}

double vec4f::operator*(const vec4f &v)
{
return x*v.x+y*v.y+z*v.z+w*v.w;
}

bool vec4f::operator==(const vec4f &v)
{
  if((x==v.x) && (y==v.y) && (z==v.z) && (w==v.w))return true;
  return false;
}

 std::ostream& operator<<(std::ostream &os,const vec4f &v)
{
return os<<"( "<<v.x<<" , "<<v.y<<" , "<<v.z<<" , "<<v.w<<" )";
}

double vec4f::getMagnitude()
{
    return sqrt(x*x+y*y+z*z+w*w);
}

vec4f operator+(double number,vec4f &v)
{
    return vec4f{number+v.x,v.y,v.z,v.w};
}
vec4f operator-(double number,vec4f &v)
{
     return vec4f{number-v.x,-v.y,-v.z,-v.w};
}
vec4f operator*(double number,vec4f &v)
{
     return vec4f{number*v.x,number*v.y,number*v.z,number*v.w};
}

vec4d::vec4d():x(0.0f),y(0.0f),z(0.0f){};
vec4d::vec4d(double _x,double _y,double _z,double _w):x(_x),y(_y),z(_z),w(_w){};

vec4d::~vec4d(){}

vec4d::vec4d(const vec2f& v):x(v.x),y(v.y),z(0.0f),w(0.0f){};
vec4d::vec4d(const vec3f& v):x(v.x),y(v.y),z(v.z),w(0.0f){};
vec4d::vec4d(const vec4f& v):x(v.x),y(v.y),z(v.z),w(v.w){};
vec4d::vec4d(const vec2d& v):x(v.x),y(v.y),z(0.0f),w(0.0f){};
vec4d::vec4d(const vec3d& v):x(v.x),y(v.y),z(v.z),w(0.0f){};
vec4d::vec4d(const vec4d& v):x(v.x),y(v.y),z(v.z),w(v.w){};

vec4d& vec4d::operator=(const vec4d &v)
{

x=v.x;
y=v.y;
z=v.z;
w=v.w;
return *this;

}

vec4d vec4d::operator+(const vec4d &v)
{
 return vec4d(x+v.x,y+v.y,z+v.z,w+v.w);

}

void vec4d::operator+=(const vec4d &v)
{
x+=v.x;
y+=v.y;
z+=v.z;
w+=v.w;

}


vec4d vec4d::operator-(const vec4d &v)
{
 return vec4d(x-v.x,y-v.y,z-v.z,w-v.w);

}

void vec4d::operator-=(const vec4d &v)
{
x-=v.x;
y-=v.y;
z-=v.z;
w-=v.w;

}

vec4d vec4d::operator*(const double& a)
{
 return vec4d(a*x,a*y,a*z,a*w);

}

void vec4d::operator*=(const double& a)
{
x*=a;
y*=a;
z*=a;
w*=a;
}
vec4d vec4d::operator/(const double& a)
{
 return vec4d(x/a,y/a,z/a,w/a);
}

void vec4d::operator/=(const double& a)
{
x/=a;
y/=a;
z/=a;
w/=a;
}

double vec4d::operator*(const vec4d &v)
{
return x*v.x+y*v.y+z*v.z+w*v.w;
}

bool vec4d::operator==(const vec4d &v)
{
  if((x==v.x) && (y==v.y) && (z==v.z) && (w==v.w))return true;
  return false;
}

 std::ostream& operator<<(std::ostream &os,const vec4d &v)
{
return os<<"( "<<v.x<<" , "<<v.y<<" , "<<v.z<<" , "<<v.w<<" )";
}

double vec4d::getMagnitude()
{
    return sqrt(x*x+y*y+z*z+w*w);
}

vec4d operator+(double number,vec4d &v)
{
    return vec4d{number+v.x,v.y,v.z,v.w};
}
vec4d operator-(double number,vec4d &v)
{
     return vec4d{number-v.x,-v.y,-v.z,-v.w};
}
vec4d operator*(double number,vec4d &v)
{
     return vec4d{number*v.x,number*v.y,number*v.z,number*v.w};
}

vec2d operator+(vec2f &v1,vec2d &v2)
{
    return vec2d(v1.x+v2.x,v1.y+v2.y);
}
vec2d operator-(vec2f &v1,vec2d &v2)
{
    return vec2d(v1.x-v2.x,v1.y-v2.y);
}
double operator*(vec2f &v1,vec2d &v2)
{
    return v1.x*v2.x+v1.y*v2.y;
}

vec3f operator+(vec2f &v1,vec3f &v2){
    return vec3f(v1.x+v2.x,v1.y+v2.y,v2.z);
}
vec3f operator-(vec2f &v1,vec3f &v2){

    return vec3f(v1.x-v2.x,v1.y-v2.y,-v2.z);
}
double operator*(vec2f &v1,vec3f &v2)
{
    return v1.x*v2.x+v1.y*v2.y;
}

vec3d operator+(vec2f &v1,vec3d &v2){
    return vec3d(v1.x+v2.x,v1.y+v2.y,v2.z);
}
vec3d operator-(vec2f &v1,vec3d &v2){

    return vec3d(v1.x-v2.x,v1.y-v2.y,-v2.z);
}
double operator*(vec2f &v1,vec3d &v2)
{
    return v1.x*v2.x+v1.y*v2.y;
}
vec3d operator+(vec2d &v1,vec3d &v2){
    return vec3d(v1.x+v2.x,v1.y+v2.y,v2.z);
}
vec3d operator-(vec2d &v1,vec3d &v2){

    return vec3d(v1.x-v2.x,v1.y-v2.y,-v2.z);
}
double operator*(vec2d &v1,vec3d &v2)
{
    return v1.x*v2.x+v1.y*v2.y;
}

vec3d operator+(vec3f &v1,vec3d &v2)
{
    return vec3d(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z);
}
vec3d operator-(vec3f &v1,vec3d &v2)
{
    return vec3d(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z);
}

double operator*(vec3f &v1,vec3d &v2)
{
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}

vec4f operator+(vec2f &v1,vec4f &v2)
{
    return vec4f(v1.x+v2.x,v1.y+v2.y,v2.z,v2.w);
}
vec4f operator-(vec2f &v1,vec4f &v2)
{
    return vec4f(v1.x-v2.x,v1.y-v2.y,-v2.z,-v2.w);
}
double operator*(vec2f &v1,vec4f &v2)
{
    return v1.x*v2.x+v1.y*v2.y;
}

vec4f operator+(vec3f &v1,vec4f &v2)
{
    return vec4f(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z,v2.w);
}
vec4f operator-(vec3f &v1,vec4f &v2)
{
    return vec4f(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z,-v2.w);
}
double operator*(vec3f &v1,vec4f &v2)
{
    return v1.x*v2.x+v1.y*v2.y+v1.z+v2.z;
}

vec4d operator+(vec2f &v1,vec4d &v2)
{
    return vec4d(v1.x+v2.x,v1.y+v2.y,v2.z,v2.w);
}
vec4d operator-(vec2f &v1,vec4d &v2)
{
    return vec4d(v1.x-v2.x,v1.y-v2.y,-v2.z,-v2.w);
}
double operator*(vec2f &v1,vec4d &v2)
{
    return v1.x*v2.x+v1.y*v2.y;
}

vec4d operator+(vec3f &v1,vec4d &v2)
{
    return vec4d(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z,v2.w);
}
vec4d operator-(vec3f &v1,vec4d &v2)
{
    return vec4d(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z,-v2.w);
}
double operator*(vec3f &v1,vec4d &v2)
{
    return v1.x*v2.x+v1.y*v2.y+v1.z+v2.z;
}
vec4d operator+(vec2d &v1,vec4d &v2)
{
    return vec4d(v1.x+v2.x,v1.y+v2.y,v2.z,v2.w);
}
vec4d operator-(vec2d &v1,vec4d &v2)
{
    return vec4d(v1.x-v2.x,v1.y-v2.y,-v2.z,-v2.w);
}
double operator*(vec2d &v1,vec4d &v2)
{
    return v1.x*v2.x+v1.y*v2.y;
}

vec4d operator+(vec3d &v1,vec4d &v2)
{
    return vec4d(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z,v2.w);
}
vec4d operator-(vec3d &v1,vec4d &v2)
{
    return vec4d(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z,-v2.w);
}
double operator*(vec3d &v1,vec4d &v2)
{
    return v1.x*v2.x+v1.y*v2.y+v1.z+v2.z;
}

vec4d operator+(vec4f &v1,vec4d &v2)
{
    return vec4d(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z,v1.w+v2.w);
}
vec4d operator-(vec4f &v1,vec4d &v2)
{
    return vec4d(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z,v1.w-v2.w);
}
double operator*(vec4f &v1,vec4d &v2)
{
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z+v1.w*v2.w;
}

vec3f crossProduct2F(const vec2f &v1,const vec2f &v2)
{
    return vec3f(0.0f,0.0f,v1.x*v2.y-v1.y*v2.x);
}
vec3d crossProduct2D(const vec2d &v1,const vec2d &v2)
{
    return vec3d(0.0f,0.0f,v1.x*v2.y-v1.y*v2.x);
}
vec3f crossProduct3F(const vec3f &v1,const vec3f &v2)
{
    return vec3f(v1.y*v2.z-v1.z*v2.y,v1.z*v2.x-v1.x*v2.z,v1.x*v2.y-v1.y*v2.x);
}
vec3d crossProduct3D(const vec3d &v1,const vec3d &v2)
{
    return vec3f(v1.y*v2.z-v1.z*v2.y,v1.z*v2.x-v1.x*v2.z,v1.x*v2.y-v1.y*v2.x);
}

vec2f vec2f::unitVector()
{
    return *this/this->getMagnitude();
}

vec2d vec2d::unitVector()
{
    return *this/this->getMagnitude();
}

vec3f vec3f::unitVector()
{
    return *this/this->getMagnitude();
}

vec3d vec3d::unitVector()
{
    return *this/this->getMagnitude();
}

vec4f vec4f::unitVector()
{
    return *this/this->getMagnitude();
}

vec4d vec4d::unitVector()
{
    return *this/this->getMagnitude();
}


complex::complex():real(0.0f),imaginary(0.0f){};
complex::complex(double _real, double _imaginary):real(_real),imaginary(_imaginary){};

complex::~complex(){};

complex& complex::operator=(const complex &z)
{ real=z.real;
  imaginary=z.imaginary;
  return *this;
}

complex& complex::operator=(const double &a)
{
 real=a;
 imaginary=0.0f;
 return *this;
}


std::ostream& operator<<(std::ostream &os, complex const &z) 
{
if(z.imaginary>0)return os<<z.real<<" + "<<z.imaginary<<'i';
else return os<<z.real<<" - "<<std::abs(z.imaginary)<<'i';
}

complex complex::operator+(const complex &z)
{
return complex(real+z.real,imaginary+z.imaginary);
}

void complex::operator+=(const complex &z)
{
real+=z.real;
imaginary+=z.imaginary;
}

complex complex::operator-(const complex &z)
{
return complex(real-z.real,imaginary-z.imaginary);
}

void complex::operator-=(const complex &z)
{
real-=z.real;
imaginary-=z.imaginary;
}

complex complex::operator*(const complex &z)
{
  return complex(real*z.real-imaginary*z.imaginary,real*z.imaginary+imaginary*z.real);
}
void complex::operator*=(const complex &z)
{ double x=real;
  real=real*z.real-imaginary*z.imaginary;
  imaginary=x*z.imaginary+imaginary*z.real;
}

double complex::abs()
{
 return std::sqrt(real*real+imaginary*imaginary);
}

complex complex::operator/(const complex &z)
{
return complex(real*z.real/(z.real*z.real+z.imaginary*z.imaginary)
-imaginary*((-z.imaginary)/(z.real*z.real+z.imaginary*z.imaginary))
,real*((-z.imaginary)/(z.real*z.real+z.imaginary*z.imaginary))
+imaginary*z.real/(z.real*z.real+z.imaginary*z.imaginary));
}

void complex::operator/=(const complex &z)
{
double x=real;
real=real*z.real/(z.real*z.real+z.imaginary*z.imaginary)
-imaginary*((-z.imaginary)/(z.real*z.real+z.imaginary*z.imaginary));
imaginary=x*((-z.imaginary)/(z.real*z.real+z.imaginary*z.imaginary))
+imaginary*z.real/(z.real*z.real+z.imaginary*z.imaginary);
}

complex complex::operator+(const double&a)
{
return complex(a+real,imaginary);
}

void complex::operator+=(const double&a)
{
real=real+a;
}

complex complex::operator-(const double&a)
{
return complex(real-a,imaginary);
}

void complex::operator-=(const double&a)
{
real=real-a;
}

complex complex::operator*(const double&a)
{
return complex(a*real,a*imaginary);
}


void complex::operator*=(const double&a)
{
real=real*a;
imaginary=imaginary*a;
}

complex complex::operator/(const double&a)
{
return complex(real/a,imaginary/a);
}

void complex::operator/=(const double&a)
{
real=real/a;
imaginary=imaginary/a;
}

bool complex::operator==(const complex &z)
{
return ((real==z.real) && (imaginary==z.imaginary));
}

bool complex::operator==(const double &a)
{
return ((real==a) && (imaginary==0));
}

complex complex::getConjugate()
{
return complex(real,-imaginary);
}

complex_double::complex_double():real(0.0f),imaginary(0.0f){};
complex_double::complex_double(double _real, double _imaginary):real(_real),imaginary(_imaginary){};

complex_double::~complex_double(){};

complex_double& complex_double::operator=(const complex_double &z)
{ real=z.real;
  imaginary=z.imaginary;
  return *this;
}

complex_double& complex_double::operator=(const double &a)
{
 real=a;
 imaginary=0.0f;
 return *this;
}


std::ostream& operator<<(std::ostream &os, complex_double const &z) 
{
if(z.imaginary>0)return os<<z.real<<" + "<<z.imaginary<<'i';
else return os<<z.real<<" - "<<std::abs(z.imaginary)<<'i';
}

complex_double complex_double::operator+(const complex_double &z)
{
return complex_double(real+z.real,imaginary+z.imaginary);
}

void complex_double::operator+=(const complex_double &z)
{
real+=z.real;
imaginary+=z.imaginary;
}

complex_double complex_double::operator-(const complex_double &z)
{
return complex_double(real-z.real,imaginary-z.imaginary);
}

void complex_double::operator-=(const complex_double &z)
{
real-=z.real;
imaginary-=z.imaginary;
}

complex_double complex_double::operator*(const complex_double &z)
{
  return complex_double(real*z.real-imaginary*z.imaginary,real*z.imaginary+imaginary*z.real);
}
void complex_double::operator*=(const complex_double &z)
{ double x=real;
  real=real*z.real-imaginary*z.imaginary;
  imaginary=x*z.imaginary+imaginary*z.real;
}

double complex_double::abs()
{
 return std::sqrt(real*real+imaginary*imaginary);
}

complex_double complex_double::operator/(const complex_double &z)
{
return complex_double(real*z.real/(z.real*z.real+z.imaginary*z.imaginary)
-imaginary*((-z.imaginary)/(z.real*z.real+z.imaginary*z.imaginary))
,real*((-z.imaginary)/(z.real*z.real+z.imaginary*z.imaginary))
+imaginary*z.real/(z.real*z.real+z.imaginary*z.imaginary));
}

void complex_double::operator/=(const complex_double &z)
{
double x=real;
real=real*z.real/(z.real*z.real+z.imaginary*z.imaginary)
-imaginary*((-z.imaginary)/(z.real*z.real+z.imaginary*z.imaginary));
imaginary=x*((-z.imaginary)/(z.real*z.real+z.imaginary*z.imaginary))
+imaginary*z.real/(z.real*z.real+z.imaginary*z.imaginary);
}

complex_double complex_double::operator+(const double&a)
{
return complex_double(a+real,imaginary);
}

void complex_double::operator+=(const double&a)
{
real=real+a;
}

complex_double complex_double::operator-(const double&a)
{
return complex_double(real-a,imaginary);
}

void complex_double::operator-=(const double&a)
{
real=real-a;
}

complex_double complex_double::operator*(const double&a)
{
return complex_double(a*real,a*imaginary);
}


void complex_double::operator*=(const double&a)
{
real=real*a;
imaginary=imaginary*a;
}

complex_double complex_double::operator/(const double&a)
{
return complex_double(real/a,imaginary/a);
}

void complex_double::operator/=(const double&a)
{
real=real/a;
imaginary=imaginary/a;
}

bool complex_double::operator==(const complex_double &z)
{
return ((real==z.real) && (imaginary==z.imaginary));
}

bool complex_double::operator==(const double &a)
{
return ((real==a) && (imaginary==0));
}

complex_double complex_double::getConjugate()
{
return complex_double(real,-imaginary);
}

vec2f::vec2f(const complex &number)
{
    this->x=number.real;
    this->y=number.imaginary;
}

vec2d::vec2d(const complex_double &number)
{
    this->x=number.real;
    this->y=number.imaginary;
}

complex::complex(const complex &z):real(z.real),imaginary(z.imaginary){}
complex_double::complex_double(const complex &z):real(z.real),imaginary(z.imaginary){}
complex_double::complex_double(const complex_double &z):real(z.real),imaginary(z.imaginary){}

mat2f::mat2f():mData{0.0f,0.0f,0.0f,0.0f}{};
mat2f::mat2f(double data[2][2])
{
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)  
        mData[i*2+j]=data[i][j];
}
mat2f::mat2f(double data[4])
{
        for(int i=0;i<4;i++)
    {
        mData[i]=data[i];
    }
}
mat2f::mat2f(const mat2f& mat)
{
    for(int i=0;i<4;i++)
    {
        mData[i]=mat.mData[i];
    }
};

mat2f& mat2f::operator=(const mat2f& mat)
{
    for(int i=0;i<4;i++)
    {
        mData[i]=mat.mData[i];
    }
    return *this;
};

mat2f mat2f::operator+(const mat2f &n)
{
    mat2f res;
        for(int i=0;i<4;i++)
    {
        res.mData[i]=this->mData[i]+n.mData[i];
    }
    return res;
}
void mat2f::operator+=(const mat2f &n)
{
    for(int i=0;i<4;i++)
    {
       mData[i]+=n.mData[i];
    }
}

mat2f mat2f::operator-(const mat2f &n)
{
    mat2f res;
        for(int i=0;i<4;i++)
    {
        res.mData[i]=this->mData[i]-n.mData[i];
    }
    return res;
}
void mat2f::operator-=(const mat2f &n)
{
    for(int i=0;i<4;i++)
    {
       mData[i]-=n.mData[i];
    }
}

mat2f mat2f::operator*(const mat2f &n)
{
    mat2f m;

for(int i=0;i<2;i++)
{
 for(int j=0;j<2;j++)
 {
    for(int k=0;k<2;k++)
    m.mData[i*2+j]= 
    m.mData[i*2+j]+(n.mData[k*2+j])*(mData[i*2+k]);
 }
}

return m;
}
void mat2f::operator*=(const mat2f &n)
{
    mat2f m;

for(int i=0;i<2;i++)
{
 for(int j=0;j<2;j++)
 {
    for(int k=0;k<2;k++)
    m.mData[i*2+j]= 
    m.mData[i*2+j]+(n.mData[k*2+j])*(mData[i*2+k]);
 }
}

for(int i=0;i<4;i++)
{
    this->mData[i]=m.mData[i];
}
}
mat2f mat2f::operator*(const double &a)
{
    mat2f m;
    for(int i=0;i<4;i++)
        m.mData[i]=mData[i]*a;
    
    return m;
}

void mat2f::operator*=(const double  &a)
{
    for(int i=0;i<4;i++)
        mData[i]*=a;

}
mat2f mat2f::operator/(const double &a)
{
    mat2f m;
    for(int i=0;i<4;i++)
        m.mData[i]=mData[i]/a;
    
    return m;
}

void mat2f::operator/=(const double  &a)
{
    for(int i=0;i<4;i++)
        mData[i]/=a;

}

bool mat2f::operator==(const mat2f &n)
{
    for(int i=0;i<4;i++)
    {
        if(mData[i]!=n.mData[i])
            return 0;
    }

    return 1;
}

vec2f mat2f::operator*(const vec2f &v)
{
    return vec2f(v.x*mData[0]+v.y*mData[1],v.x*mData[2]+v.y*mData[3]);
}

double* mat2f::operator[](unsigned int index)
{  
    if(index>1)
    {
        throw "Index out of bounds";
    }
    else
     return &mData[index*2];
}

void mat2f::setElement(unsigned int i,unsigned int j,double value)
{
    mData[i*2+j]=value;
}
double mat2f::getElement(unsigned int i,unsigned int j)
{
    return mData[i*2+j];
}
double mat2f::getDeterminant()
{
    return mData[3]*mData[0]-mData[1]*mData[2];
}
mat2f mat2f::getTranspose()
{
    mat2f m;
    m.mData[0]=mData[0];
    m.mData[3]=mData[3];
    m.mData[1]=mData[2];
    m.mData[2]=mData[1];
    return m;
}
mat2f mat2f::getInverse()
{
if(getDeterminant()==0)return mat2f();
mat2f t;
t.mData[0]=mData[3];
t.mData[1]=-mData[1];
t.mData[2]=-mData[2];
t.mData[3]=mData[0];
t/=getDeterminant();
return t;
}

std::ostream& operator<<(std::ostream &os,const mat2f &mat)
{
    os<<"("<<mat.mData[0]<<','<<mat.mData[1]<<')'<<'\n';
    os<<"("<<mat.mData[2]<<','<<mat.mData[3]<<')'<<'\n';
    return os;
}

mat2d::mat2d():mData{0.0f,0.0f,0.0f,0.0f}{};
mat2d::mat2d(double data[2][2])
{
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)  
        mData[i*2+j]=data[i][j];
}
mat2d::mat2d(double data[4])
{
        for(int i=0;i<4;i++)
    {
        mData[i]=data[i];
    }
}
mat2d::mat2d(const mat2d& mat)
{
    for(int i=0;i<4;i++)
    {
        mData[i]=mat.mData[i];
    }
};

mat2d& mat2d::operator=(const mat2d& mat)
{
    for(int i=0;i<4;i++)
    {
        mData[i]=mat.mData[i];
    }
    return *this;
};

mat2d mat2d::operator+(const mat2d &n)
{
    mat2d res;
        for(int i=0;i<4;i++)
    {
        res.mData[i]=this->mData[i]+n.mData[i];
    }
    return res;
}
void mat2d::operator+=(const mat2d &n)
{
    for(int i=0;i<4;i++)
    {
       mData[i]+=n.mData[i];
    }
}

mat2d mat2d::operator-(const mat2d &n)
{
    mat2d res;
        for(int i=0;i<4;i++)
    {
        res.mData[i]=this->mData[i]-n.mData[i];
    }
    return res;
}
void mat2d::operator-=(const mat2d &n)
{
    for(int i=0;i<4;i++)
    {
       mData[i]-=n.mData[i];
    }
}

mat2d mat2d::operator*(const mat2d &n)
{
    mat2d m;

for(int i=0;i<2;i++)
{
 for(int j=0;j<2;j++)
 {
    for(int k=0;k<2;k++)
    m.mData[i*2+j]= 
    m.mData[i*2+j]+(n.mData[k*2+j])*(mData[i*2+k]);
 }
}
return m;
}
void mat2d::operator*=(const mat2d &n)
{
    mat2d m;

for(int i=0;i<2;i++)
{
 for(int j=0;j<2;j++)
 {
    for(int k=0;k<2;k++)
    m.mData[i*2+j]= 
    m.mData[i*2+j]+(n.mData[k*2+j])*(mData[i*2+k]);
 }
}

for(int i=0;i<4;i++)
{
    this->mData[i]=m.mData[i];
}
}
mat2d mat2d::operator*(const double &a)
{
    mat2d m;
    for(int i=0;i<4;i++)
        m.mData[i]=mData[i]*a;
    
    return m;
}

void mat2d::operator*=(const double  &a)
{
    for(int i=0;i<4;i++)
        mData[i]*=a;

}
mat2d mat2d::operator/(const double &a)
{
    mat2d m;
    for(int i=0;i<4;i++)
        m.mData[i]=mData[i]/a;
    
    return m;
}

void mat2d::operator/=(const double  &a)
{
    for(int i=0;i<4;i++)
        mData[i]/=a;

}

bool mat2d::operator==(const mat2d &n)
{
    for(int i=0;i<4;i++)
    {
        if(mData[i]!=n.mData[i])
            return 0;
    }

    return 1;
}

vec2d mat2d::operator*(const vec2d &v)
{
    return vec2d(v.x*mData[0]+v.y*mData[1],v.x*mData[2]+v.y*mData[3]);
}

double* mat2d::operator[](unsigned int index)
{  
    if(index>1)
    {
        throw "Index out of bounds";
    }
    else
     return &mData[index*2];
}

void mat2d::setElement(unsigned int i,unsigned int j,double value)
{
    mData[i*2+j]=value;
}
double mat2d::getElement(unsigned int i,unsigned int j)
{
    return mData[i*2+j];
}
double mat2d::getDeterminant()
{
    return mData[3]*mData[0]-mData[1]*mData[2];
}
mat2d mat2d::getTranspose()
{
    mat2d m;
    m.mData[0]=mData[0];
    m.mData[3]=mData[3];
    m.mData[1]=mData[2];
    m.mData[2]=mData[1];
    return m;
}
mat2d mat2d::getInverse()
{
if(getDeterminant()==0)return mat2d();
mat2d t;
t.mData[0]=mData[3];
t.mData[1]=-mData[1];
t.mData[2]=-mData[2];
t.mData[3]=mData[0];
t/=getDeterminant();
return t;
}

std::ostream& operator<<(std::ostream &os,const mat2d &mat)
{
    os<<"("<<mat.mData[0]<<','<<mat.mData[1]<<')'<<'\n';
    os<<"("<<mat.mData[2]<<','<<mat.mData[3]<<')'<<'\n';
    return os;
}

mat3f::mat3f():mData{0.0f,0.0f,0.0f,0.0f
,0.0f,0.0f,0.0f,0.0f,0.0f}{};
mat3f::mat3f(double data[3][3])
{
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)  
        mData[i*3+j]=data[i][j];
}
mat3f::mat3f(double data[9])
{
        for(int i=0;i<9;i++)
    {
        mData[i]=data[i];
    }
}
mat3f::mat3f(const mat3f& mat)
{
    for(int i=0;i<9;i++)
    {
        mData[i]=mat.mData[i];
    }
};

mat3f& mat3f::operator=(const mat3f& mat)
{
    for(int i=0;i<9;i++)
    {
        mData[i]=mat.mData[i];
    }
    return *this;
};

mat3f mat3f::operator+(const mat3f &n)
{
    mat3f res;
        for(int i=0;i<9;i++)
    {
        res.mData[i]=this->mData[i]+n.mData[i];
    }
    return res;
}
void mat3f::operator+=(const mat3f &n)
{
    for(int i=0;i<9;i++)
    {
       mData[i]+=n.mData[i];
    }
}

mat3f mat3f::operator-(const mat3f &n)
{
    mat3f res;
        for(int i=0;i<9;i++)
    {
        res.mData[i]=this->mData[i]-n.mData[i];
    }
    return res;
}

void mat3f::operator-=(const mat3f &n)
{
    for(int i=0;i<9;i++)
    {
       mData[i]-=n.mData[i];
    }
}

mat3f mat3f::operator*(const mat3f &n)
{
    mat3f m;

for(int i=0;i<3;i++)
{
 for(int j=0;j<3;j++)
 {
    for(int k=0;k<3;k++)
    m.mData[i*3+j]= 
    m.mData[i*3+j]+(n.mData[k*3+j])*(mData[i*3+k]);
 }
}
return m;
}

void mat3f::operator*=(const mat3f &n)
{
    mat3f m;

for(int i=0;i<3;i++)
{
 for(int j=0;j<3;j++)
 {
    for(int k=0;k<3;k++)
    m.mData[i*3+j]= 
    m.mData[i*3+j]+(n.mData[k*3+j])*(mData[i*3+k]);
 }
}

for(int i=0;i<9;i++)
{
    this->mData[i]=m.mData[i];
}
}

mat3f mat3f::operator*(const double &a)
{
    mat3f m;
    for(int i=0;i<9;i++)
        m.mData[i]=mData[i]*a;
    
    return m;
}

void mat3f::operator*=(const double  &a)
{
    for(int i=0;i<9;i++)
        mData[i]*=a;

}
mat3f mat3f::operator/(const double &a)
{
    mat3f m;
    for(int i=0;i<9;i++)
        m.mData[i]=mData[i]/a;
    
    return m;
}

void mat3f::operator/=(const double  &a)
{
    for(int i=0;i<9;i++)
        mData[i]/=a;

}

bool mat3f::operator==(const mat3f &n)
{
    for(int i=0;i<9;i++)
    {
        if(mData[i]!=n.mData[i])
            return 0;
    }

    return 1;
}

vec3f mat3f::operator*(const vec3f &v)
{
    return vec3f(v.x*mData[0]+v.y*mData[1]+v.z*mData[2],v.x*mData[3]+v.y*mData[4]+v.z*mData[5],v.x*mData[6]+v.y*mData[7]+v.z*mData[8]);
}

double* mat3f::operator[](unsigned int index)
{  
    if(index>2)
    {
        throw "Index out of bounds";
    }
    else
     return &mData[index*3];
}

void mat3f::setElement(unsigned int i,unsigned int j,double value)
{
    mData[i*3+j]=value;
}
double mat3f::getElement(unsigned int i,unsigned int j)
{
    return mData[i*3+j];
}
double mat3f::getDeterminant()
{
    return  
  mData[0]*mData[4]*mData[8]+
  mData[5]*mData[1]*mData[6]+
  mData[2]*mData[3]*mData[7]-
  mData[2]*mData[4]*mData[6]-
  mData[0]*mData[5]*mData[7]-
  mData[8]*mData[1]*mData[3];
}
mat3f mat3f::getTranspose()
{
    mat3f m;
    m.mData[0]=mData[0];
    m.mData[1]=mData[3];
    m.mData[2]=mData[6];
    m.mData[3]=mData[1];
    m.mData[4]=mData[4];
    m.mData[5]=mData[7];
    m.mData[6]=mData[2];
    m.mData[7]=mData[5];
    m.mData[8]=mData[8];

    return m;
}
mat3f mat3f::getInverse()
{
if(getDeterminant()==0)return mat3f();
else{
mat3f m;
mat3f t=this->getTranspose();
for(int i=0;i<3;i++){
for(int j=0;j<3;j++)
{
    mat2f n;
    int a=0;
    for(int y=0;y<3;y++)
    for(int z=0;z<3;z++)
    {
      if(y!=i && z!=j){
        n.mData[a]=t.mData[y*3+z];
      a++;
      }
    }
m.mData[i*3+j]=(1-2*((i+j)%2))*n.getDeterminant();
}
}

return m/getDeterminant();
}
}

std::ostream& operator<<(std::ostream &os,const mat3f &mat)
{
    os<<"("<<mat.mData[0]<<','<<mat.mData[1]<<','<<mat.mData[2]<<')'<<'\n';
    os<<"("<<mat.mData[3]<<','<<mat.mData[4]<<','<<mat.mData[5]<<')'<<'\n';
    os<<"("<<mat.mData[6]<<','<<mat.mData[7]<<','<<mat.mData[8]<<')'<<'\n';
    return os;
}

mat3d::mat3d():mData{0.0f,0.0f,0.0f,0.0f
,0.0f,0.0f,0.0f,0.0f,0.0f}{};
mat3d::mat3d(double data[3][3])
{
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)  
        mData[i*3+j]=data[i][j];
}
mat3d::mat3d(double data[9])
{
        for(int i=0;i<9;i++)
    {
        mData[i]=data[i];
    }
}
mat3d::mat3d(const mat3d& mat)
{
    for(int i=0;i<9;i++)
    {
        mData[i]=mat.mData[i];
    }
};

mat3d& mat3d::operator=(const mat3d& mat)
{
    for(int i=0;i<9;i++)
    {
        mData[i]=mat.mData[i];
    }
    return *this;
};

mat3d mat3d::operator+(const mat3d &n)
{
    mat3d res;
        for(int i=0;i<9;i++)
    {
        res.mData[i]=this->mData[i]+n.mData[i];
    }
    return res;
}
void mat3d::operator+=(const mat3d &n)
{
    for(int i=0;i<9;i++)
    {
       mData[i]+=n.mData[i];
    }
}

mat3d mat3d::operator-(const mat3d &n)
{
    mat3d res;
        for(int i=0;i<9;i++)
    {
        res.mData[i]=this->mData[i]-n.mData[i];
    }
    return res;
}

void mat3d::operator-=(const mat3d &n)
{
    for(int i=0;i<9;i++)
    {
       mData[i]-=n.mData[i];
    }
}

mat3d mat3d::operator*(const mat3d &n)
{
    mat3d m;

for(int i=0;i<3;i++)
{
 for(int j=0;j<3;j++)
 {
    for(int k=0;k<3;k++)
    m.mData[i*3+j]= 
    m.mData[i*3+j]+(n.mData[k*3+j])*(mData[i*3+k]);
 }
}
return m;
}

void mat3d::operator*=(const mat3d &n)
{
    mat3d m;

for(int i=0;i<3;i++)
{
 for(int j=0;j<3;j++)
 {
    for(int k=0;k<3;k++)
    m.mData[i*3+j]= 
    m.mData[i*3+j]+(n.mData[k*3+j])*(mData[i*3+k]);
 }
}

for(int i=0;i<9;i++)
{
    this->mData[i]=m.mData[i];
}
}

mat3d mat3d::operator*(const double &a)
{
    mat3d m;
    for(int i=0;i<9;i++)
        m.mData[i]=mData[i]*a;
    
    return m;
}

void mat3d::operator*=(const double  &a)
{
    for(int i=0;i<9;i++)
        mData[i]*=a;

}
mat3d mat3d::operator/(const double &a)
{
    mat3d m;
    for(int i=0;i<9;i++)
        m.mData[i]=mData[i]/a;
    
    return m;
}

void mat3d::operator/=(const double  &a)
{
    for(int i=0;i<9;i++)
        mData[i]/=a;

}

bool mat3d::operator==(const mat3d &n)
{
    for(int i=0;i<9;i++)
    {
        if(mData[i]!=n.mData[i])
            return 0;
    }

    return 1;
}

vec3d mat3d::operator*(const vec3d &v)
{
        return vec3d(v.x*mData[0]+v.y*mData[1]+v.z*mData[2],v.x*mData[3]+v.y*mData[4]+v.z*mData[5],v.x*mData[6]+v.y*mData[7]+v.z*mData[8]);
}

double* mat3d::operator[](unsigned int index)
{  
    if(index>2)
    {
        throw "Index out of bounds";
    }
    else
     return &mData[index*3];
}

void mat3d::setElement(unsigned int i,unsigned int j,double value)
{
    mData[i*3+j]=value;
}
double mat3d::getElement(unsigned int i,unsigned int j)
{
    return mData[i*3+j];
}
double mat3d::getDeterminant()
{
    return  
  mData[0]*mData[4]*mData[8]+
  mData[5]*mData[1]*mData[6]+
  mData[2]*mData[3]*mData[7]-
  mData[2]*mData[4]*mData[6]-
  mData[0]*mData[5]*mData[7]-
  mData[8]*mData[1]*mData[3];
}
mat3d mat3d::getTranspose()
{
    mat3d m;
    m.mData[0]=mData[0];
    m.mData[1]=mData[3];
    m.mData[2]=mData[6];
    m.mData[3]=mData[1];
    m.mData[4]=mData[4];
    m.mData[5]=mData[7];
    m.mData[6]=mData[2];
    m.mData[7]=mData[5];
    m.mData[8]=mData[8];

    return m;
}
mat3d mat3d::getInverse()
{
if(getDeterminant()==0)return mat3d();
else{
mat3d m;
mat3d t=this->getTranspose();
for(int i=0;i<3;i++){
for(int j=0;j<3;j++)
{
    mat2d n;
    int a=0;
    for(int y=0;y<3;y++)
    for(int z=0;z<3;z++)
    {
      if(y!=i && z!=j){
        n.mData[a]=t.mData[y*3+z];
      a++;
      }
    }
m.mData[i*3+j]=(1-2*((i+j)%2))*n.getDeterminant();
}
}

return m/getDeterminant();
}
}

std::ostream& operator<<(std::ostream &os,const mat3d &mat)
{
    os<<"("<<mat.mData[0]<<','<<mat.mData[1]<<','<<mat.mData[2]<<')'<<'\n';
    os<<"("<<mat.mData[3]<<','<<mat.mData[4]<<','<<mat.mData[5]<<')'<<'\n';
    os<<"("<<mat.mData[6]<<','<<mat.mData[7]<<','<<mat.mData[8]<<')'<<'\n';
    return os;
}

mat4f::mat4f():mData{0.0f,0.0f,0.0f,0.0f
,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f
,0.0f,0.0f}{};
mat4f::mat4f(double data[4][4])
{
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)  
        mData[i*4+j]=data[i][j];
}
mat4f::mat4f(double data[16])
{
        for(int i=0;i<16;i++)
    {
        mData[i]=data[i];
    }
}
mat4f::mat4f(const mat4f& mat)
{
    for(int i=0;i<16;i++)
    {
        mData[i]=mat.mData[i];
    }
};

mat4f& mat4f::operator=(const mat4f& mat)
{
    for(int i=0;i<16;i++)
    {
        mData[i]=mat.mData[i];
    }
    return *this;
};

mat4f mat4f::operator+(const mat4f &n)
{
    mat4f res;
        for(int i=0;i<16;i++)
    {
        res.mData[i]=this->mData[i]+n.mData[i];
    }
    return res;
}
void mat4f::operator+=(const mat4f &n)
{
    for(int i=0;i<16;i++)
    {
       mData[i]+=n.mData[i];
    }
}

mat4f mat4f::operator-(const mat4f &n)
{
    mat4f res;
        for(int i=0;i<16;i++)
    {
        res.mData[i]=this->mData[i]-n.mData[i];
    }
    return res;
}

void mat4f::operator-=(const mat4f &n)
{
    for(int i=0;i<16;i++)
    {
       mData[i]-=n.mData[i];
    }
}

mat4f mat4f::operator*(const mat4f &n)
{
    mat4f m;

for(int i=0;i<4;i++)
{
 for(int j=0;j<4;j++)
 {
    for(int k=0;k<4;k++)
    m.mData[i*4+j]= 
    m.mData[i*4+j]+(n.mData[k*4+j])*(mData[i*4+k]);
 }
}
return m;
}

void mat4f::operator*=(const mat4f &n)
{
    mat4f m;

for(int i=0;i<4;i++)
{
 for(int j=0;j<4;j++)
 {
    for(int k=0;k<4;k++)
    m.mData[i*4+j]= 
    m.mData[i*4+j]+(n.mData[k*4+j])*(mData[i*4+k]);
 }
}

for(int i=0;i<16;i++)
{
    this->mData[i]=m.mData[i];
}
}

mat4f mat4f::operator*(const double &a)
{
    mat4f m;
    for(int i=0;i<16;i++)
        m.mData[i]=mData[i]*a;
    
    return m;
}

void mat4f::operator*=(const double  &a)
{
    for(int i=0;i<16;i++)
        mData[i]*=a;

}
mat4f mat4f::operator/(const double &a)
{
    mat4f m;
    for(int i=0;i<16;i++)
        m.mData[i]=mData[i]/a;
    
    return m;
}

void mat4f::operator/=(const double  &a)
{
    for(int i=0;i<16;i++)
        mData[i]/=a;

}

bool mat4f::operator==(const mat4f &n)
{
    for(int i=0;i<16;i++)
    {
        if(mData[i]!=n.mData[i])
            return 0;
    }

    return 1;
}

vec4f mat4f::operator*(const vec4f &v)
{
    return vec4f(v.x*mData[0]+v.y*mData[1]+v.z*mData[2]+v.w*mData[3]
                ,v.x*mData[4]+v.y*mData[5]+v.z*mData[6]+v.w*mData[7]
                ,v.x*mData[8]+v.y*mData[9]+v.z*mData[10]+v.w*mData[11]
                ,v.x*mData[12]+v.y*mData[13]+v.z*mData[14]+v.w*mData[15]);
}

double* mat4f::operator[](unsigned int index)
{  
    if(index>3)
    {
        throw "Index out of bounds";
    }
    else
     return &mData[index*4];
}

void mat4f::setElement(unsigned int i,unsigned int j,double value)
{
    mData[i*4+j]=value;
}
double mat4f::getElement(unsigned int i,unsigned int j)
{
    return mData[i*4+j];
}
double mat4f::getDeterminant()
{
double s=0;
    for(int j=0;j<4;j++)
    {
      mat3f m;
      int a=0;
      for(int i=1;i<4;i++)
      {
        for(int k=0;k<4;k++)
        {
         if(k!=j){m.mData[a]=mData[i*4+k];
           a++;
         }
        }
      }

     s=s+mData[j]*(1-2*(j%2))*m.getDeterminant();

    }
    return s;
}
mat4f mat4f::getTranspose()
{
mat4f m;

for(int j=0;j<4;j++){
for(int i=0;i<4;i++)
m.mData[j*4+i]=mData[i*4+j];
}

return m;
}

mat4f mat4f::getInverse()
{
if(getDeterminant()==0)return mat4f();
else{
mat4f m;
mat4f t=this->getTranspose();
for(int i=0;i<4;i++){
for(int j=0;j<4;j++)
{
    mat3f n;
    int a=0;
    for(int y=0;y<4;y++)
    for(int z=0;z<4;z++)
    {
      if(y!=i && z!=j){
        n.mData[a]=t.mData[y*4+z];
      a++;
      }
    }
m.mData[i*4+j]=(1-2*((i+j)%2))*n.getDeterminant();
}
}

return m/getDeterminant();
}
}

std::ostream& operator<<(std::ostream &os,const mat4f &mat)
{
    os<<"("<<mat.mData[0]<<','<<mat.mData[1]<<','<<mat.mData[2]<<','<<mat.mData[3]<<')'<<'\n';
    os<<"("<<mat.mData[4]<<','<<mat.mData[5]<<','<<mat.mData[6]<<','<<mat.mData[7]<<')'<<'\n';
    os<<"("<<mat.mData[8]<<','<<mat.mData[9]<<','<<mat.mData[10]<<','<<mat.mData[11]<<')'<<'\n';
    os<<"("<<mat.mData[12]<<','<<mat.mData[13]<<','<<mat.mData[14]<<','<<mat.mData[15]<<')'<<'\n';
    return os;
}

mat4d::mat4d():mData{0.0f,0.0f,0.0f,0.0f
,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f
,0.0f,0.0f}{};
mat4d::mat4d(double data[4][4])
{
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)  
        mData[i*4+j]=data[i][j];
}
mat4d::mat4d(double data[16])
{
        for(int i=0;i<16;i++)
    {
        mData[i]=data[i];
    }
}
mat4d::mat4d(const mat4d& mat)
{
    for(int i=0;i<16;i++)
    {
        mData[i]=mat.mData[i];
    }
};

mat4d& mat4d::operator=(const mat4d& mat)
{
    for(int i=0;i<16;i++)
    {
        mData[i]=mat.mData[i];
    }
    return *this;
};

mat4d mat4d::operator+(const mat4d &n)
{
    mat4d res;
        for(int i=0;i<16;i++)
    {
        res.mData[i]=this->mData[i]+n.mData[i];
    }
    return res;
}
void mat4d::operator+=(const mat4d &n)
{
    for(int i=0;i<16;i++)
    {
       mData[i]+=n.mData[i];
    }
}

mat4d mat4d::operator-(const mat4d &n)
{
    mat4d res;
        for(int i=0;i<16;i++)
    {
        res.mData[i]=this->mData[i]-n.mData[i];
    }
    return res;
}

void mat4d::operator-=(const mat4d &n)
{
    for(int i=0;i<16;i++)
    {
       mData[i]-=n.mData[i];
    }
}

mat4d mat4d::operator*(const mat4d &n)
{
    mat4d m;

for(int i=0;i<4;i++)
{
 for(int j=0;j<4;j++)
 {
    for(int k=0;k<4;k++)
    m.mData[i*4+j]= 
    m.mData[i*4+j]+(n.mData[k*4+j])*(mData[i*4+k]);
 }
}
return m;
}

void mat4d::operator*=(const mat4d &n)
{
    mat4d m;

for(int i=0;i<4;i++)
{
 for(int j=0;j<4;j++)
 {
    for(int k=0;k<4;k++)
    m.mData[i*4+j]= 
    m.mData[i*4+j]+(n.mData[k*4+j])*(mData[i*4+k]);
 }
}

for(int i=0;i<16;i++)
{
    this->mData[i]=m.mData[i];
}
}

mat4d mat4d::operator*(const double &a)
{
    mat4d m;
    for(int i=0;i<16;i++)
        m.mData[i]=mData[i]*a;
    
    return m;
}

void mat4d::operator*=(const double  &a)
{
    for(int i=0;i<16;i++)
        mData[i]*=a;

}
mat4d mat4d::operator/(const double &a)
{
    mat4d m;
    for(int i=0;i<16;i++)
        m.mData[i]=mData[i]/a;
    
    return m;
}

void mat4d::operator/=(const double  &a)
{
    for(int i=0;i<16;i++)
        mData[i]/=a;

}

bool mat4d::operator==(const mat4d &n)
{
    for(int i=0;i<16;i++)
    {
        if(mData[i]!=n.mData[i])
            return 0;
    }

    return 1;
}

vec4d mat4d::operator*(const vec4d &v)
{
    return vec4d(v.x*mData[0]+v.y*mData[1]+v.z*mData[2]+v.w*mData[3]
                ,v.x*mData[4]+v.y*mData[5]+v.z*mData[6]+v.w*mData[7]
                ,v.x*mData[8]+v.y*mData[9]+v.z*mData[10]+v.w*mData[11]
                ,v.x*mData[12]+v.y*mData[13]+v.z*mData[14]+v.w*mData[15]);
}

double* mat4d::operator[](unsigned int index)
{  
    if(index>3)
    {
        throw "Index out of bounds";
    }
    else
     return &mData[index*4];
}

void mat4d::setElement(unsigned int i,unsigned int j,double value)
{
    mData[i*4+j]=value;
}
double mat4d::getElement(unsigned int i,unsigned int j)
{
    return mData[i*4+j];
}
double mat4d::getDeterminant()
{
double s=0;
    for(int j=0;j<4;j++)
    {
      mat3d m;
      int a=0;
      for(int i=1;i<4;i++)
      {
        for(int k=0;k<4;k++)
        {
         if(k!=j){m.mData[a]=mData[i*4+k];
           a++;
         }
        }
      }

     s=s+mData[j]*(1-2*(j%2))*m.getDeterminant();

    }
    return s;
}
mat4d mat4d::getTranspose()
{
mat4d m;

for(int j=0;j<4;j++){
for(int i=0;i<4;i++)
m.mData[j*4+i]=mData[i*4+j];
}

return m;
}

mat4d mat4d::getInverse()
{
if(getDeterminant()==0)return mat4d();
else{
mat4d m;
mat4d t=this->getTranspose();
for(int i=0;i<4;i++){
for(int j=0;j<4;j++)
{
    mat3d n;
    int a=0;
    for(int y=0;y<4;y++)
    for(int z=0;z<4;z++)
    {
      if(y!=i && z!=j){
        n.mData[a]=t.mData[y*4+z];
      a++;
      }
    }
m.mData[i*4+j]=(1-2*((i+j)%2))*n.getDeterminant();
}
}

return m/getDeterminant();
}
}

std::ostream& operator<<(std::ostream &os,const mat4d &mat)
{
    os<<"("<<mat.mData[0]<<','<<mat.mData[1]<<','<<mat.mData[2]<<','<<mat.mData[3]<<')'<<'\n';
    os<<"("<<mat.mData[4]<<','<<mat.mData[5]<<','<<mat.mData[6]<<','<<mat.mData[7]<<')'<<'\n';
    os<<"("<<mat.mData[8]<<','<<mat.mData[9]<<','<<mat.mData[10]<<','<<mat.mData[11]<<')'<<'\n';
    os<<"("<<mat.mData[12]<<','<<mat.mData[13]<<','<<mat.mData[14]<<','<<mat.mData[15]<<')'<<'\n';
    return os;
}

Matrix::Matrix():nOfRows(3),nOfColumns(3)
{
mData=new double[9];
for(int i=0;i<9;i++)mData[i]=0.0f;
};

Matrix::Matrix(int _nOfRows,int _nOfColumns):nOfRows(_nOfRows),nOfColumns(_nOfColumns)
{
mData=new double[nOfColumns*nOfRows];
for(int i=0;i<nOfRows*nOfColumns;i++)mData[i]=0.0f;
};

Matrix::Matrix(int _nOfRows,int _nOfColumns,unsigned int arraySize ,const double* inputData):nOfRows(_nOfRows),nOfColumns(_nOfColumns)
{
mData=new double[nOfColumns*nOfRows];
for(int i=0;i<nOfRows*nOfColumns;i++)
{
  if(i<arraySize)mData[i]=inputData[i];
  else
    mData[i]=0.0f;
}
};

Matrix::~Matrix(){
    if(mData!=nullptr)
        {
            delete[] mData;
        }
};

std::ostream& operator<<(std::ostream &os, Matrix const &m)
{ 

  for(int i=0;i<m.nOfRows;i++){
  os<<"[ ";
  for(int j=0;j<m.nOfColumns;j++)os<<m.mData[i*m.nOfColumns+j]<<' ';
  os<<"]";
  os<<'\n';
  }

  return os;
};

double* Matrix::operator[](const unsigned int &a)
{
    if(a>nOfRows)
    {
        throw "Index out of bounds";
    }
    else 
        return &mData[a*nOfColumns];
}

double  Matrix::getElement(const int &n, const int &m)
{
return mData[n*nOfColumns+m];
}

void  Matrix::setElement(const int &n, const int &m,const double &a)
{
mData[n*nOfColumns+m] = a;
}

Matrix::Matrix(const Matrix &m):
 nOfRows(m.nOfRows),nOfColumns(m.nOfColumns)
 {
    mData=new double[nOfColumns*nOfRows];
    for(int i=0;i<nOfColumns*nOfRows;i++)
    {
        mData[i]=m.mData[i];
    }
 };
 
Matrix& Matrix::operator=(const Matrix &m)
{
nOfRows = m.nOfRows;
nOfColumns = m.nOfColumns;

if(mData!=nullptr)
{
    delete[] mData;
    mData=0;
}

  mData=new double[nOfColumns*nOfRows];
    for(int i=0;i<nOfColumns*nOfRows;i++)
    {
        mData[i]=m.mData[i];
    }
return *this;

}


Matrix Matrix::operator+(const Matrix &n)
{
  
if((nOfRows==n.nOfRows) && (nOfColumns==n.nOfColumns))
{
Matrix m(nOfRows,nOfColumns);
for(int i=0;i<nOfColumns*nOfRows;i++)m.mData[i]=mData[i]+n.mData[i];
return m;
}
return O3;
}

void Matrix::operator+=(const Matrix &n)
{
if((nOfRows==n.nOfRows) && (nOfColumns==n.nOfColumns))

 for(int i=0;i<nOfColumns*nOfRows;i++)mData[i]=mData[i]+n.mData[i];


}

Matrix Matrix::operator-(const Matrix &n)
{
  
if((nOfRows==n.nOfRows) && (nOfColumns==n.nOfColumns))
{
Matrix m(nOfRows,nOfColumns);
for(int i=0;i<nOfColumns*nOfRows;i++)m.mData[i]=mData[i]-n.mData[i];
return m;
}
return O3;
}

void Matrix::operator-=(const Matrix &n)
{
if((nOfRows==n.nOfRows) && (nOfColumns==n.nOfColumns))

 for(int i=0;i<nOfColumns*nOfRows;i++)mData[i]=mData[i]-n.mData[i];


}

Matrix Matrix::operator*(const double &a)
{
  Matrix m(nOfRows,nOfColumns);
 for(int i=0;i<nOfColumns*nOfRows;i++) m.mData[i] = mData[i]*a;

 return m;

}

void Matrix::operator*=(const double &a)
{
 
 for(int i=0;i<nOfColumns*nOfRows;i++) mData[i] = mData[i]*a;
 

}

Matrix Matrix::operator/(const double &a)
{
  Matrix m(nOfRows,nOfColumns);
 for(int i=0;i<nOfColumns*nOfRows;i++) m.mData[i] = mData[i]/a;

 return m;

}

void Matrix::operator/=(const double &a)
{
 
 for(int i=0;i<nOfColumns*nOfRows;i++) mData[i] = mData[i]/a;
 

}

bool Matrix::operator==(const Matrix &n)
{
if((nOfRows==n.nOfRows) && (nOfColumns== n.nOfColumns))
{
for(int i=0;i<nOfColumns*nOfRows;i++)if(mData[i]!=n.mData[i])return false;

return true;
}

return false;
}


 Matrix Matrix::operator*(const Matrix &n)
 {
if (nOfColumns!=n.nOfRows) return I3;


Matrix m(nOfRows,n.nOfColumns);

for(int i=0;i<nOfRows;i++)
{
 for(int j=0;j<n.nOfColumns;j++)
 {
    for(int k=0;k<n.nOfRows;k++)
    m.mData[i*m.nOfColumns+j]= 
    m.mData[i*m.nOfColumns+j]+(n.mData[k*n.nOfColumns+j])*(mData[i*nOfColumns+k]);
 }
}

return m;
 }

void Matrix::operator*=(const Matrix &n)
 {


Matrix m(nOfRows,n.nOfColumns);

for(int i=0;i<nOfRows;i++)
{
 for(int j=0;j<n.nOfColumns;j++)
 {
    for(int k=0;k<n.nOfRows;k++)
    m.mData[i*m.nOfColumns+j]= 
    m.mData[i*m.nOfColumns+j]+(n.mData[k*n.nOfColumns+j])*(mData[i*nOfColumns+k]);
 }
}

*this=m;

 }

 double Matrix::getDeterminant()
 {
  
  if(nOfColumns!=nOfRows)return 0.0f;
  
  if(nOfColumns==1)return mData[0];
  
  if(nOfColumns==2) {return mData[0]*mData[3]-mData[1]*mData[2];}
  
  if(nOfColumns==3) {return 
  mData[0]*mData[4]*mData[8]+
  mData[5]*mData[1]*mData[6]+
  mData[2]*mData[3]*mData[7]-
  mData[2]*mData[4]*mData[6]-
  mData[0]*mData[5]*mData[7]-
  mData[8]*mData[1]*mData[3];
  }

  if(nOfColumns>3)
  {double s=0;
    for(int j=0;j<nOfColumns;j++)
    {
      Matrix m(nOfColumns-1,nOfColumns-1);
      int a=0;
      for(int i=1;i<nOfRows;i++)
      {
        for(int k=0;k<nOfColumns;k++)
        {
         if(k!=j){m.mData[a]=mData[i*nOfColumns+k];
           a++;
         }
        }
      }

     s=s+mData[j]*(1-2*(j%2))*m.getDeterminant();

    }
    return s;
  }
  
  return 0.0f;
 }

Matrix Matrix::getTranspose()
{
Matrix m(nOfColumns,nOfRows);

for(int j=0;j<nOfColumns;j++){
for(int i=0;i<nOfRows;i++)
m.mData[j*nOfRows+i]=mData[i*nOfColumns+j];
}

return m;

}


Matrix Matrix::getInverse()
{
if(nOfColumns!=nOfRows || getDeterminant()==0)return O3;
else{
Matrix m(nOfColumns,nOfColumns);
Matrix t=this->getTranspose();
for(int i=0;i<nOfColumns;i++){
for(int j=0;j<nOfRows;j++)
{
    Matrix n(nOfColumns-1,nOfColumns-1);
    int a=0;
    for(int y=0;y<nOfColumns;y++)
    for(int z=0;z<nOfRows;z++)
    {
      if(y!=i && z!=j){
        n.mData[a]=t.mData[y*nOfColumns+z];
      a++;
      }
    }
m.mData[i*nOfColumns+j]=(1-2*((i+j)%2))*n.getDeterminant();
}
}

return m/getDeterminant();
}
}

quaternion::quaternion():real(0.0f),imaginary(vec3f(0.0f,0.0f,0.0f)){};
quaternion::quaternion(double _real, vec3f _imaginary):real(_real),imaginary(_imaginary){};

quaternion::~quaternion(){};

double quaternion::abs()
{
  return real*real + imaginary*imaginary;
}

quaternion quaternion::getConjugate()
{
  return quaternion(real,imaginary*(-1));
}

quaternion& quaternion::operator=(const quaternion &q)
{
real=q.real;
imaginary=q.imaginary;

return *this;
}

quaternion& quaternion::operator=(const double &a)
{
real=a;
imaginary=vec3f();
return *this;
}

quaternion& quaternion::operator=(const complex &z)
{
real=z.real;
imaginary=vec3f(z.imaginary,0,0);
return *this;
}
quaternion& quaternion::operator=(const vec3f &v)
{
real=0;
imaginary=v;
return *this;
}

std::ostream& operator<<(std::ostream &os, quaternion const &q)
{
  return os<<"( "<<q.real<<' '<<q.imaginary.x<<' '<<q.imaginary.y<<' '<<q.imaginary.z<<" )";
}

quaternion quaternion::operator+(const quaternion &q)
{
return quaternion(real+q.real,imaginary+q.imaginary);
}

void quaternion::operator+=(const quaternion &q)
{
real+=q.real;
imaginary+=q.imaginary;
}

quaternion quaternion::operator-(const quaternion &q)
{
return quaternion(real-q.real,imaginary-q.imaginary);
}

void quaternion::operator-=(const quaternion &q)
{
real-=q.real;
imaginary-=q.imaginary;
}

quaternion quaternion::operator*(const quaternion &q)
{
return quaternion(real*q.real-imaginary*q.imaginary
,(q.imaginary*real)+(imaginary*q.real)+crossProduct3F(imaginary, q.imaginary));
}

void quaternion::operator*=(const quaternion &q)
{
double x=real;
real=real*q.real-imaginary*q.imaginary;
imaginary=(q.imaginary*x)+(imaginary*q.real)+crossProduct3F(imaginary, q.imaginary);

}




bool quaternion::operator==(const quaternion &q)
{
return ((real==q.real) && (imaginary==q.imaginary));
}

quaternion quaternion::operator+(const double &a)
{
return quaternion(real+a,imaginary);
}

void quaternion::operator+=(const double &a)
{
real=real+a;
}
quaternion quaternion::operator-(const double &a)
{
return quaternion(real-a,imaginary);
}

void quaternion::operator-=(const double &a)
{
real=real-a;
}

quaternion quaternion::operator*(const double &a)
{
return quaternion(real*a,imaginary*a);
}

void quaternion::operator*=(const double &a)
{
real=real*a;
imaginary=imaginary*a;
}

quaternion quaternion::operator/(const double &a)
{
return quaternion(real/a,imaginary/a);
}

void quaternion::operator/=(const double &a)
{
real=real/a;
imaginary=imaginary/a;
}

bool quaternion::operator==(const double &a)
{
  if(imaginary==vec3f()){
  if(real==a)return true;
  }
  return false;
}

quaternion quaternion::getUnitquaternion()
{
return *this/this->abs();
}

quaternion quaternion::getInverse()
{
double norm=this->abs();
return quaternion(real/norm,(imaginary*(-1))/norm);
}

quaternion quaternion::operator/(const quaternion &q)
{
quaternion d=q;

return *this*d.getInverse();
}

void  quaternion::operator/=(const quaternion &q)
{
quaternion d=q;

*this=*this*d.getInverse();
}


quaternion quaternion::operator+(const complex &z)
{
return quaternion(real+z.real,imaginary + vec3f(z.imaginary,0.0f,0.0f));
}

void quaternion::operator+=(const complex &z)
{
  real+=z.real;
  imaginary+=vec3f(z.imaginary,0,0);
}

quaternion quaternion::operator-(const complex &z)
{
return quaternion(real+z.real,imaginary - vec3f(z.imaginary,0.0f,0.0f));
}

void quaternion::operator-=(const complex &z)
{
  real-=z.real;
  imaginary-=vec3f(z.imaginary,0,0);
}

quaternion quaternion::operator*(const complex &z)
{
return (*this)*quaternion(z.real,vec3f(z.imaginary,0.0f,0.0f));
}

void quaternion::operator*=(const complex &z)
{
 *this=(*this)*quaternion(z.real,vec3f(z.imaginary,0.0f,0.0f));
}

quaternion quaternion::operator/(const complex &z)
{
return (*this)/quaternion(z.real,vec3f(z.imaginary,0.0f,0.0f));
}

void quaternion::operator/=(const complex &z)
{
 *this=(*this)/quaternion(z.real,vec3f(z.imaginary,0.0f,0.0f));
}

quaternion quaternion::operator+(const vec3f &v)
{
return quaternion(real,imaginary+v);
}

void quaternion::operator+=(const vec3f &v)
{
imaginary+=v;
}

quaternion quaternion::operator-(const vec3f &v)
{
return quaternion(real,imaginary-v);
}

void quaternion::operator-=(const vec3f &v)
{
imaginary-=v;
}

quaternion quaternion::operator*(const vec3f &v)
{
return (*this)*quaternion(0.0f,v);
}

void quaternion::operator*=(const vec3f &v)
{
 *this=(*this)*quaternion(0.0f,v);
}

quaternion quaternion::operator/(const vec3f &v)
{
return (*this)/quaternion(0.0f,v);
}

void quaternion::operator/=(const vec3f &v)
{
 *this=(*this)/quaternion(0.0f,v);
}

quaternion_double::quaternion_double():real(0.0f),imaginary(vec3d(0.0f,0.0f,0.0f)){};
quaternion_double::quaternion_double(double _real, vec3d _imaginary):real(_real),imaginary(_imaginary){};

quaternion_double::~quaternion_double(){};

double quaternion_double::abs()
{
  return real*real + imaginary*imaginary;
}

quaternion_double quaternion_double::getConjugate()
{
  return quaternion_double(real,imaginary*(-1));
}

quaternion_double& quaternion_double::operator=(const quaternion_double &q)
{
real=q.real;
imaginary=q.imaginary;

return *this;
}

quaternion_double& quaternion_double::operator=(const double &a)
{
real=a;
imaginary=vec3d();
return *this;
}

quaternion_double& quaternion_double::operator=(const complex_double &z)
{
real=z.real;
imaginary=vec3d(z.imaginary,0,0);
return *this;
}
quaternion_double& quaternion_double::operator=(const vec3d &v)
{
real=0;
imaginary=v;
return *this;
}

std::ostream& operator<<(std::ostream &os, quaternion_double const &q)
{
  return os<<"( "<<q.real<<' '<<q.imaginary.x<<' '<<q.imaginary.y<<' '<<q.imaginary.z<<" )";
}

quaternion_double quaternion_double::operator+(const quaternion_double &q)
{
return quaternion_double(real+q.real,imaginary+q.imaginary);
}

void quaternion_double::operator+=(const quaternion_double &q)
{
real+=q.real;
imaginary+=q.imaginary;
}

quaternion_double quaternion_double::operator-(const quaternion_double &q)
{
return quaternion_double(real-q.real,imaginary-q.imaginary);
}

void quaternion_double::operator-=(const quaternion_double &q)
{
real-=q.real;
imaginary-=q.imaginary;
}

quaternion_double quaternion_double::operator*(const quaternion_double &q)
{
return quaternion_double(real*q.real-imaginary*q.imaginary
,(q.imaginary*real)+(imaginary*q.real)+crossProduct3D(imaginary, q.imaginary));
}

void quaternion_double::operator*=(const quaternion_double &q)
{
double x=real;
real=real*q.real-imaginary*q.imaginary;
imaginary=(q.imaginary*x)+(imaginary*q.real)+crossProduct3D(imaginary, q.imaginary);

}




bool quaternion_double::operator==(const quaternion_double &q)
{
return ((real==q.real) && (imaginary==q.imaginary));
}

quaternion_double quaternion_double::operator+(const double &a)
{
return quaternion_double(real+a,imaginary);
}

void quaternion_double::operator+=(const double &a)
{
real=real+a;
}
quaternion_double quaternion_double::operator-(const double &a)
{
return quaternion_double(real-a,imaginary);
}

void quaternion_double::operator-=(const double &a)
{
real=real-a;
}

quaternion_double quaternion_double::operator*(const double &a)
{
return quaternion_double(real*a,imaginary*a);
}

void quaternion_double::operator*=(const double &a)
{
real=real*a;
imaginary=imaginary*a;
}

quaternion_double quaternion_double::operator/(const double &a)
{
return quaternion_double(real/a,imaginary/a);
}

void quaternion_double::operator/=(const double &a)
{
real=real/a;
imaginary=imaginary/a;
}

bool quaternion_double::operator==(const double &a)
{
  if(imaginary==vec3d()){
  if(real==a)return true;
  }
  return false;
}

quaternion_double quaternion_double::getUnitquaternion()
{
return *this/this->abs();
}

quaternion_double quaternion_double::getInverse()
{
double norm=this->abs();
return quaternion_double(real/norm,(imaginary*(-1))/norm);
}

quaternion_double quaternion_double::operator/(const quaternion_double &q)
{
quaternion_double d=q;

return *this*d.getInverse();
}

void  quaternion_double::operator/=(const quaternion_double &q)
{
quaternion_double d=q;

*this=*this*d.getInverse();
}


quaternion_double quaternion_double::operator+(const complex_double &z)
{
return quaternion_double(real+z.real,imaginary + vec3d(z.imaginary,0.0f,0.0f));
}

void quaternion_double::operator+=(const complex_double &z)
{
  real+=z.real;
  imaginary+=vec3d(z.imaginary,0,0);
}

quaternion_double quaternion_double::operator-(const complex_double &z)
{
return quaternion_double(real+z.real,imaginary - vec3d(z.imaginary,0.0f,0.0f));
}

void quaternion_double::operator-=(const complex_double &z)
{
  real-=z.real;
  imaginary-=vec3d(z.imaginary,0,0);
}

quaternion_double quaternion_double::operator*(const complex_double &z)
{
return (*this)*quaternion_double(z.real,vec3d(z.imaginary,0.0f,0.0f));
}

void quaternion_double::operator*=(const complex_double &z)
{
 *this=(*this)*quaternion_double(z.real,vec3d(z.imaginary,0.0f,0.0f));
}

quaternion_double quaternion_double::operator/(const complex_double &z)
{
return (*this)/quaternion_double(z.real,vec3d(z.imaginary,0.0f,0.0f));
}

void quaternion_double::operator/=(const complex_double &z)
{
 *this=(*this)/quaternion_double(z.real,vec3d(z.imaginary,0.0f,0.0f));
}

quaternion_double quaternion_double::operator+(const vec3d &v)
{
return quaternion_double(real,imaginary+v);
}

void quaternion_double::operator+=(const vec3d &v)
{
imaginary+=v;
}

quaternion_double quaternion_double::operator-(const vec3d &v)
{
return quaternion_double(real,imaginary-v);
}

void quaternion_double::operator-=(const vec3d &v)
{
imaginary-=v;
}

quaternion_double quaternion_double::operator*(const vec3d &v)
{
return (*this)*quaternion_double(0.0f,v);
}

void quaternion_double::operator*=(const vec3d &v)
{
 *this=(*this)*quaternion_double(0.0f,v);
}

quaternion_double quaternion_double::operator/(const vec3d &v)
{
return (*this)/quaternion_double(0.0f,v);
}

void quaternion_double::operator/=(const vec3d &v)
{
 *this=(*this)/quaternion_double(0.0f,v);
}

    Vector::Vector(int size):
    size(size)
    {
        if(size>0)
            this->vData = new double[size]();
        else
            this->vData=nullptr;
    }
    Vector::Vector(int size,double* data):
    size(size)
    {
        if(size>0){
            this->vData = new double[size];
            for(int i=0;i<size;i++)
            {
                this->vData[i] = data[i];
            }
        }
        else
            this->vData=nullptr;
    }

    Vector::Vector(const Vector& vec)
    {
        this->size = vec.size;
        if(this->size>0 && vec.vData!=NULL)
        {
            this->vData = new double[size];
            for(int i=0;i<size;i++)
            {
                this->vData[i] = vec.vData[i];
            }
        }
        else
            this->vData = nullptr;
    }

    Vector& Vector::operator=(const Vector& vec)
    {
        if(&vec==this)
            return *this;

        if(this->vData!=NULL)
            delete[] vData;

        this->size = vec.size;
        if(this->size>0 && vec.vData!=NULL)
        {
            this->vData = new double[size];
            for(int i=0;i<size;i++)
            {
                this->vData[i] = vec.vData[i];
            }
        }
        else
            this->vData = nullptr;

        return *this;
    }

    Vector Vector::operator+(const Vector &v) const
    {
        Vector newVec(std::max(v.size,this->size));
        for(int i=0;i<newVec.size;i++)
        {
            if(i>=v.size)
            {
                newVec.vData[i] = this->vData[i];
            }
            else if(i>=this->size)
            {
                newVec.vData[i] = v.vData[i];
            }
            else
                newVec.vData[i] = this->vData[i]+v.vData[i];
        }

        return newVec;
    }
    void Vector::operator+=(const Vector &v)
    {
         if(v.size>this->size)
        {
            *this = *this+v;
            return;
        }

            for(int i=0;i<this->size;i++)
        {
            if(i<v.size)
                this->vData[i] = this->vData[i]+v.vData[i];
        }
    }

    Vector Vector::operator-(const Vector &v) const
    {
        Vector newVec(std::max(v.size,this->size));
        for(int i=0;i<newVec.size;i++)
        {
            if(i>=v.size)
            {
                newVec.vData[i] = this->vData[i];
            }
            else if(i>=this->size)
            {
                newVec.vData[i] = -v.vData[i];
            }
            else
                newVec.vData[i] = this->vData[i]-v.vData[i];
        }
        return newVec;
    }
    
    void Vector::operator-=(const Vector &v)
    {
        if(v.size>this->size)
        {
            *this = *this-v;
            return;
        }

            for(int i=0;i<this->size;i++)
        {
            if(i<v.size)
                this->vData[i] = this->vData[i]-v.vData[i];
        }
    }

    double Vector::operator*(const Vector &v) const
    {
        double sum=0;
        int i=0;
        while(i<v.size && i<this->size)
        {
            sum += v.vData[i]*this->vData[i];
            i++;
        }
        return sum;
    }

    Vector Vector::operator*(const double &a) const
    {
        Vector vec(this->size);
        for(int i=0;i<size;i++)
        {
            vec.vData[i] = this->vData[i]*a;
        }
        return vec;
    }
    void Vector::operator*=(const double &a)
    {
        for(int i=0;i<size;i++)
            this->vData[i]*=a;
    }
    Vector Vector::operator/(const double &a) const
    {
        Vector vec(this->size);
        for(int i=0;i<size;i++)
        {
            vec.vData[i] = this->vData[i]/a;
        }
        return vec;
    }
    void Vector::operator/=(const double &a)
    {
        for(int i=0;i<size;i++)
            this->vData[i]/=a;
    }
    bool Vector::operator==(const Vector &v) const
    {
        if(v.size!=this->size)
            return 0;
        for(int i=0;i<v.size;i++)
        {
            if(this->vData[i]!=v.vData[i])
                return 0;
        }
        return 1;
    }
    Vector Vector::operator*(Matrix &mat) const
    {
        if(mat.nOfRows!=this->size)
            return Vector(mat.nOfColumns);
        Vector newVec(mat.nOfColumns);
        for(int i=0;i<mat.nOfColumns;i++)
        {
            for(int j=0;j<this->size;j++ )
            {
                newVec.vData[i] += this->vData[j]*mat[j][i];
            }
        }
        return newVec;
    }

    Vector::~Vector()
    {
        if(vData!=NULL)
        {
            delete [] vData;
            vData = NULL;
        }
    };
    std::string Vector::ToString() const
    {
        std::string res = "[";
        if(this->size>0 && this->vData!=NULL)
        {
            res += std::to_string(this->vData[0]);
            for(int i=1;i<this->size;i++)
            {
                res+=","+std::to_string(this->vData[i]);
            }
        }
        res+="]";
        return res;
    }
    double Vector::getMagnitude() const
    {
        double sum = 0;
        for(int i=0;i<this->size;i++)
        {
            sum+=this->vData[i]*this->vData[i];
        }
        return sqrt(sum);
    }
    Vector Vector::unitVector() const
    {
        return (*this)/this->getMagnitude();
    }
    int Vector::getSize() const
    {
        return this->size;
    }
    double Vector::getElement(int index) const
    {
        if(index>size)
        {
            throw "Index out of bounds";
        }
        return this->vData[index];
    }
    void Vector::setElement(int index,double newElement)
    {
        if(index>size)
        {
            throw "Index out of bounds";
        }
        this->vData[index] = newElement;
    }
    double& Vector::operator[](int index)
    {
            {
        if(index>size)
        {
            throw "Index out of bounds";
        }
        return this->vData[index];
    }
    }
    bool Vector::isUnit() const
    {
        return 0.99<getMagnitude()<1.01;
    }
    bool Vector::isNull() const
    {
        for(int i=0;i<this->size;i++)
        {
            if(this->vData[i]!=0)
                return 0;
        }
        return 1;
    }
    bool Vector::isValid() const
    {
        return this->size>0 && this->vData!=NULL;
    }

    Vector operator*(Matrix& mat,Vector& vec)
    {
        if(mat.nOfColumns!=vec.getSize())
            return Vector(mat.nOfRows);
        Vector newVec = Vector(mat.nOfRows);

        for(int i=0;i<mat.nOfRows;i++)
        {  
            for(int j=0;j<mat.nOfColumns;j++)
            {
                newVec[i] += mat[i][j]*vec[j];
            }
        }
        return newVec;
    }
/*
    1 1 1  1 1 
           1 1  3 3
           1 1

    1 1 1   1
    1 1 1   1   3 3
            1
*/
}