
#pragma once
#include <iostream>



namespace Math
{
const double PI = 3.14159265358979323846f;
const double EULER_NUMBER=2.718281828459045f;
const int TRANSFORMATION_TYPE=0;

double degreesToRad(const double &x);

const double theoremeOfCosine(double l1,double l2, double angle);
const double polygonRfinder(double l,double angle);



class complex
{
public:
double real;
double imaginary;

complex();
complex(double _real, double _imaginary);
complex(const complex &z);

~complex();

double abs();
complex getConjugate();

complex& operator=(const complex &z);
complex& operator=(const double &a);

friend std::ostream& operator<<(std::ostream &os, complex const &z) ;

complex operator+(const complex &z);
void operator+=(const complex &z);
complex operator-(const complex &z);
void operator-=(const complex &z);
complex operator*(const complex &z);
void operator*=(const complex &z);
complex operator/(const complex &z);
void operator/=(const complex &z);
bool operator==(const complex &z);

complex operator+(const double&a);
void operator+=(const double&a);
complex operator-(const double&a);
void operator-=(const double&a);
complex operator*(const double&a);
void operator*=(const double&a);
complex operator/(const double&a);
void operator/=(const double&a);
bool operator==(const double &a);



private:

};


class complex_double
{
public:
double real;
double imaginary;

complex_double();
complex_double(double _real, double _imaginary);
complex_double(const complex_double &z);
complex_double(const complex &z);

~complex_double();

double abs();
complex_double getConjugate();

complex_double& operator=(const complex_double &z);
complex_double& operator=(const double &a);

friend std::ostream& operator<<(std::ostream &os, complex_double const &z) ;

complex_double operator+(const complex_double &z);
void operator+=(const complex_double &z);
complex_double operator-(const complex_double &z);
void operator-=(const complex_double &z);
complex_double operator*(const complex_double &z);
void operator*=(const complex_double &z);
complex_double operator/(const complex_double &z);
void operator/=(const complex_double &z);
bool operator==(const complex_double &z);

complex_double operator+(const double&a);
void operator+=(const double&a);
complex_double operator-(const double&a);
void operator-=(const double&a);
complex_double operator*(const double&a);
void operator*=(const double&a);
complex_double operator/(const double&a);
void operator/=(const double&a);
bool operator==(const double &a);



private:

};

class vec2f
{
public:

double x; 
double y; 


vec2f();
vec2f(double _x , double _y);


~vec2f();

vec2f(const complex &number);
vec2f(const vec2f &v);
vec2f& operator=(const vec2f &v);


friend std::ostream& operator<<(std::ostream &os, vec2f const &m) ;


vec2f operator+(const vec2f &v);
void  operator+=(const vec2f &v);
vec2f operator-(const vec2f &v);
void operator-=(const vec2f &v);
double operator*(const vec2f &v);
void operator*=(const double &a);
vec2f operator*(const double &a);
void operator/=(const double &a);
vec2f operator/(const double &a); 
bool operator==(const vec2f &v);

vec2f unitVector();
double getMagnitude();

private:
};

vec2f operator+(double number,vec2f &v);
vec2f operator-(double number,vec2f &v);
vec2f operator*(double number,vec2f &v);



class vec2d
{
public:

double x; 
double y; 

vec2d();
vec2d(double _x , double _y);
vec2d(const complex_double &number);
vec2d(const vec2f &v);


~vec2d();


vec2d(const vec2d &v);
vec2d& operator=(const vec2d &v);


friend std::ostream& operator<<(std::ostream &os, vec2d const &m) ;


vec2d operator+(const vec2d &v);
void  operator+=(const vec2d &v);
vec2d operator-(const vec2d &v);
void operator-=(const vec2d &v);
double operator*(const vec2d &v);
void operator*=(const double &a);
vec2d operator*(const double &a);
void operator/=(const double &a);
vec2d operator/(const double &a); 
bool operator==(const vec2d &v);

double getMagnitude();
vec2d unitVector();

private:
};

vec2d operator+(double number,vec2d &v);
vec2d operator-(double number,vec2d &v);
vec2d operator*(double number,vec2d &v);



class vec3f 
{
public:


double x; 
double y; 
double z; 


vec3f();
vec3f(double _x , double _y, double _z);

~vec3f();


vec3f(const vec2f &v);
vec3f(const vec3f &v);
vec3f& operator=(const vec3f &v);


friend std::ostream& operator<<(std::ostream &os, vec3f const &m) ;



vec3f operator+(const vec3f &v);
void operator+=(const vec3f &v);
vec3f operator-(const vec3f &v);
void operator-=(const vec3f &v);
double operator*(const vec3f &v);
vec3f operator*(const double &a)const;
void operator*=(const double &a);
vec3f operator/(const double &a);
void operator/=(const double &a);
bool operator==(const vec3f &v);

double getMagnitude();
vec3f unitVector();

private:


};

vec3f operator+(double number,vec3f &v);
vec3f operator-(double number,vec3f &v);
vec3f operator*(double number,vec3f &v);

class vec3d 
{
public:


double x; 
double y; 
double z; 


vec3d();
vec3d(double _x , double _y, double _z);

~vec3d();

vec3d(const vec2f &v);
vec3d(const vec2d &v);
vec3d(const vec3f &v);
vec3d(const vec3d &v);
vec3d& operator=(const vec3d &v);


friend std::ostream& operator<<(std::ostream &os, vec3d const &m) ;



vec3d operator+(const vec3d &v);
void operator+=(const vec3d &v);
vec3d operator-(const vec3d &v);
void operator-=(const vec3d &v);
double operator*(const vec3d &v);
vec3d operator*(const double &a)const;
void operator*=(const double &a);
vec3d operator/(const double &a);
void operator/=(const double &a);
bool operator==(const vec3d &v);

double getMagnitude();
vec3d unitVector();


private:


};

vec3d operator+(double number,vec3d &v);
vec3d operator-(double number,vec3d &v);
vec3d operator*(double number,vec3d &v);

class vec4f 
{
public:


double x; 
double y; 
double z; 
double w;

vec4f();
vec4f(double _x , double _y, double _z,double _w);


~vec4f();

vec4f(const vec2f &v);
vec4f(const vec3f &v);
vec4f(const vec4f &v);
vec4f& operator=(const vec4f &v);


friend std::ostream& operator<<(std::ostream &os, vec4f const &m) ;


vec4f operator+(const vec4f &v);
void operator+=(const vec4f &v);
vec4f operator-(const vec4f &v);
void operator-=(const vec4f &v);
double operator*(const vec4f &v);
vec4f operator*(const double &a);
void operator*=(const double &a);
vec4f operator/(const double &a);
void operator/=(const double &a);
bool operator==(const vec4f &v);

double getMagnitude();
vec4f unitVector();
private:


};

vec4f operator+(double number,vec4f &v);
vec4f operator-(double number,vec4f &v);
vec4f operator*(double number,vec4f &v);


class vec4d 
{
public:


double x; 
double y; 
double z; 
double w;

vec4d();
vec4d(double _x , double _y, double _z,double _w);


~vec4d();

vec4d(const vec2f &v);
vec4d(const vec3f &v);
vec4d(const vec2d &v);
vec4d(const vec3d &v);
vec4d(const vec4f &v);
vec4d(const vec4d &v);
vec4d& operator=(const vec4d &v);


friend std::ostream& operator<<(std::ostream &os, vec4d const &m) ;


vec4d operator+(const vec4d &v);
void operator+=(const vec4d &v);
vec4d operator-(const vec4d &v);
void operator-=(const vec4d &v);
double operator*(const vec4d &v);
vec4d operator*(const double &a);
void operator*=(const double &a);
vec4d operator/(const double &a);
void operator/=(const double &a);
bool operator==(const vec4d &v);

double getMagnitude();
vec4d unitVector();
private:


};

vec4d operator+(double number,vec4d &v);
vec4d operator-(double number,vec4d &v);
vec4d operator*(double number,vec4d &v);

vec2d operator+(vec2f &v1,vec2d &v2);
vec2d operator-(vec2f &v1,vec2d &v2);
double operator*(vec2f &v1,vec2d &v2);

vec3f operator+(vec2f &v1,vec3f &v2);
vec3f operator-(vec2f &v1,vec3f &v2);
double operator*(vec2f &v1,vec3f &v2);

vec3d operator+(vec2f &v1,vec3d &v2);
vec3d operator-(vec2f &v1,vec3d &v2);
double operator*(vec2f &v1,vec3d &v2);

vec3d operator+(vec2d &v1,vec3d &v2);
vec3d operator-(vec2d &v1,vec3d &v2);
double operator*(vec2d &v1,vec3d &v2);

vec3d operator+(vec3f &v1,vec3d &v2);
vec3d operator-(vec3f &v1,vec3d &v2);
double operator*(vec3f &v1,vec3d &v2);

vec4f operator+(vec2f &v1,vec4f &v2);
vec4f operator-(vec2f &v1,vec4f &v2);
double operator*(vec2f &v1,vec4f &v2);

vec4f operator+(vec3f &v1,vec4f &v2);
vec4f operator-(vec3f &v1,vec4f &v2);
double operator*(vec3f &v1,vec4f &v2);

vec4d operator+(vec2f &v1,vec4d &v2);
vec4d operator-(vec2f &v1,vec4d &v2);
double operator*(vec2f &v1,vec4d &v2);

vec4d operator+(vec3f &v1,vec4d &v2);
vec4d operator-(vec3f &v1,vec4d &v2);
double operator*(vec3f &v1,vec4d &v2);

vec4d operator+(vec2d &v1,vec4d &v2);
vec4d operator-(vec2d &v1,vec4d &v2);
double operator*(vec2d &v1,vec4d &v2);

vec4d operator+(vec3d &v1,vec4d &v2);
vec4d operator-(vec3d &v1,vec4d &v2);
double operator*(vec3d &v1,vec4d &v2);

vec4d operator+(vec4f &v1,vec4d &v2);
vec4d operator-(vec4f &v1,vec4d &v2);
double operator*(vec4f &v1,vec4d &v2);

vec3f crossProduct2F(const vec2f &v1,const vec2f &v2);
vec3d crossProduct2D(const vec2d &v1,const vec2d &v2);
vec3f crossProduct3F(const vec3f &v1,const vec3f &v2);
vec3d crossProduct3D(const vec3d &v1,const vec3d &v2);

class mat2f
{
public:
mat2f();
mat2f(double data[2][2]);
mat2f(double data[4]);
mat2f(const mat2f& mat);

mat2f& operator=(const mat2f& mat);

mat2f operator+(const mat2f &n);
void operator+=(const mat2f &n);
mat2f operator-(const mat2f &n);
void operator-=(const mat2f &n);
mat2f operator*(const mat2f &n);
void operator*=(const mat2f &n);
mat2f operator*(const double &a);
void operator*=(const double  &a);
mat2f operator/(const double &a);
void operator/=(const double  &a);
bool operator==(const mat2f &n);

friend std::ostream& operator<<(std::ostream &os,const mat2f &mat);

vec2f operator*(const vec2f &v);

double* operator[](unsigned int index);

void setElement(unsigned int i,unsigned int j,double value);
double getElement(unsigned int i,unsigned int j);
double getDeterminant();
mat2f getTranspose();
mat2f getInverse();

friend class mat3f;

private:
double mData[4];
};

class mat2d
{
public:
mat2d();
mat2d(double data[2][2]);
mat2d(double data[4]);
mat2d(const mat2d& mat);

mat2d& operator=(const mat2d& mat);

mat2d operator+(const mat2d &n);
void operator+=(const mat2d &n);
mat2d operator-(const mat2d &n);
void operator-=(const mat2d &n);
mat2d operator*(const mat2d &n);
void operator*=(const mat2d &n);
mat2d operator*(const double &a);
void operator*=(const double  &a);
mat2d operator/(const double &a);
void operator/=(const double  &a);
bool operator==(const mat2d &n);

friend std::ostream& operator<<(std::ostream &os,const mat2d &mat);

vec2d operator*(const vec2d &v);

double* operator[](unsigned int index);

void setElement(unsigned int i,unsigned int j,double value);
double getElement(unsigned int i,unsigned int j);
double getDeterminant();
mat2d getTranspose();
mat2d getInverse();

friend class mat3d;

private:
double mData[4];
};

class mat3f
{
public:
mat3f();
mat3f(double data[3][3]);
mat3f(double data[9]);
mat3f(const mat3f& mat);

mat3f& operator=(const mat3f& mat);

mat3f operator+(const mat3f &n);
void operator+=(const mat3f &n);
mat3f operator-(const mat3f &n);
void operator-=(const mat3f &n);
mat3f operator*(const mat3f &n);
void operator*=(const mat3f &n);
mat3f operator*(const double &a);
void operator*=(const double  &a);
mat3f operator/(const double &a);
void operator/=(const double  &a);
bool operator==(const mat3f &n);

friend std::ostream& operator<<(std::ostream &os,const mat3f &mat);

vec3f operator*(const vec3f &v);

double* operator[](unsigned int index);

void setElement(unsigned int i,unsigned int j,double value);
double getElement(unsigned int i,unsigned int j);
double getDeterminant();
mat3f getTranspose();
mat3f getInverse();

friend class mat4f;

private:
double mData[9];
};

class mat3d
{
public:
mat3d();
mat3d(double data[3][3]);
mat3d(double data[9]);
mat3d(const mat3d& mat);

mat3d& operator=(const mat3d& mat);

mat3d operator+(const mat3d &n);
void operator+=(const mat3d &n);
mat3d operator-(const mat3d &n);
void operator-=(const mat3d &n);
mat3d operator*(const mat3d &n);
void operator*=(const mat3d &n);
mat3d operator*(const double &a);
void operator*=(const double  &a);
mat3d operator/(const double &a);
void operator/=(const double  &a);
bool operator==(const mat3d &n);

friend std::ostream& operator<<(std::ostream &os,const mat3d &mat);

vec3d operator*(const vec3d &v);

double* operator[](unsigned int index);

void setElement(unsigned int i,unsigned int j,double value);
double getElement(unsigned int i,unsigned int j);
double getDeterminant();
mat3d getTranspose();
mat3d getInverse();

friend class mat4d;

private:
double mData[9];
};

class mat4f
{
public:
mat4f();
mat4f(double data[4][4]);
mat4f(double data[16]);
mat4f(const mat4f& mat);

mat4f& operator=(const mat4f& mat);

mat4f operator+(const mat4f &n);
void operator+=(const mat4f &n);
mat4f operator-(const mat4f &n);
void operator-=(const mat4f &n);
mat4f operator*(const mat4f &n);
void operator*=(const mat4f &n);
mat4f operator*(const double &a);
void operator*=(const double  &a);
mat4f operator/(const double &a);
void operator/=(const double  &a);
bool operator==(const mat4f &n);

friend std::ostream& operator<<(std::ostream &os,const mat4f &mat);

vec4f operator*(const vec4f &v);

double* operator[](unsigned int index);

void setElement(unsigned int i,unsigned int j,double value);
double getElement(unsigned int i,unsigned int j);
double getDeterminant();
mat4f getTranspose();
mat4f getInverse();

private:
double mData[16];
};

class mat4d
{
public:
mat4d();
mat4d(double data[4][4]);
mat4d(double data[16]);
mat4d(const mat4d& mat);

mat4d& operator=(const mat4d& mat);

mat4d operator+(const mat4d &n);
void operator+=(const mat4d &n);
mat4d operator-(const mat4d &n);
void operator-=(const mat4d &n);
mat4d operator*(const mat4d &n);
void operator*=(const mat4d &n);
mat4d operator*(const double &a);
void operator*=(const double  &a);
mat4d operator/(const double &a);
void operator/=(const double  &a);
bool operator==(const mat4d &n);

friend std::ostream& operator<<(std::ostream &os,const mat4d &mat);

vec4d operator*(const vec4d &v);

double* operator[](unsigned int index);

void setElement(unsigned int i,unsigned int j,double value);
double getElement(unsigned int i,unsigned int j);
double getDeterminant();
mat4d getTranspose();
mat4d getInverse();

private:
double mData[16];
};


class Matrix
{
public:
double* mData;
int nOfRows;
int nOfColumns;
int liniarIndex;

Matrix();
Matrix(int _nOfRows,int _nOfColumns);
Matrix(int _nOfRows,int _nOfColumns,unsigned int arraySize, const double* inputData);



~Matrix();


friend std::ostream& operator<<(std::ostream &os, Matrix const &m) ;



void setElement(const int &n, const int &m,const double &a);
double getElement(const int &n, const int &m);
double getDeterminant();
Matrix getInverse();
Matrix getTranspose();

Matrix(const Matrix &v);
Matrix& operator=(const Matrix &v);


double* operator[](const unsigned int &a);
Matrix operator+(const Matrix &n);
void operator+=(const Matrix &n);
Matrix operator-(const Matrix &n);
void operator-=(const Matrix &n);
Matrix operator*(const Matrix &n);
void operator*=(const Matrix &n);
Matrix operator*(const double &a);
void operator*=(const double  &a);
Matrix operator/(const double &a);
void operator/=(const double  &a);
bool operator==(const Matrix &n);
friend class Vector;

private:
};

const mat2f O2F;
const mat2d O2D;

const mat3f O3F;
const mat3d O3D;

const mat4f O4F;
const mat4d O4D;

const mat2f I2F((double[4]){
1.0f,0.0f,
0.0f,1.0f});

const mat2d I2D((double[4]){
1.0f,0.0f,
0.0f,1.0f});

const mat3f I3F((double[9]){
1.0f,0.0f,0.0f,
0.0f,1.0f,0.0f,
0.0f,0.0f,1.0f});

const mat3d I3D((double[9]){
1.0f,0.0f,0.0f,
0.0f,1.0f,0.0f,
0.0f,0.0f,1.0f});

const mat4f I4F((double[16]){
1.0f,0.0f,0.0f,0.0f,
0.0f,1.0f,0.0f,0.0f,
0.0f,0.0f,1.0f,0.0f,
0.0f,0.0f,0.0f,1.0f
});
const mat4d I4D((double[16]){
1.0f,0.0f,0.0f,0.0f,
0.0f,1.0f,0.0f,0.0f,
0.0f,0.0f,1.0f,0.0f,
0.0f,0.0f,0.0f,1.0f
});


const Matrix O3;
const Matrix I3(3, 3,9, static_cast<const double*>(std::initializer_list<double>{
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
}.begin()));

class quaternion
{
public:
double real;
vec3f imaginary;

quaternion();
quaternion(double _real, vec3f _imaginary);
~quaternion();

quaternion& operator=(const quaternion &q);
quaternion& operator=(const double &a);
quaternion& operator=(const complex &z);
quaternion& operator=(const vec3f &v);


double abs();
quaternion getConjugate();

friend std::ostream& operator<<(std::ostream &os, quaternion const &q) ;

quaternion operator+(const quaternion &q);
void operator+=(const quaternion &q);
quaternion operator-(const quaternion &q);
void operator-=(const quaternion &q);
quaternion operator*(const quaternion &q);
void operator*=(const quaternion &q);
bool operator==(const quaternion &q);

quaternion operator+(const double &a);
void operator+=(const double &a);
quaternion operator-(const double &a);
void operator-=(const double &a);
quaternion operator*(const double &a);
void operator*=(const double &a);
quaternion operator/(const double &a);
void operator/=(const double &a);
bool operator==(const double &a);


quaternion getUnitquaternion();
quaternion getInverse();
quaternion operator/(const quaternion&q);
void operator/=(const quaternion &q);

quaternion operator+(const complex &z);
void operator+=(const complex &z);
quaternion operator-(const complex &z);
void operator-=(const complex &z);
quaternion operator*(const complex &z);
void operator*=(const complex &z);
quaternion operator/(const complex &z);
void operator/=(const complex &z);
bool operator==(const complex &z);

quaternion operator+(const vec3f &v);
void operator+=(const vec3f &v);
quaternion operator-(const vec3f &v);
void operator-=(const vec3f &v);
quaternion operator*(const vec3f &v);
void operator*=(const vec3f &v);
quaternion operator/(const vec3f &v);
void operator/=(const vec3f &v);
bool operator==(const vec3f &v);




private:

};

class quaternion_double
{
public:
double real;
vec3d imaginary;

quaternion_double();
quaternion_double(double _real, vec3d _imaginary);
~quaternion_double();

quaternion_double& operator=(const quaternion_double &q);
quaternion_double& operator=(const double &a);
quaternion_double& operator=(const Math::complex_double &z);
quaternion_double& operator=(const vec3d &v);


double abs();
quaternion_double getConjugate();

friend std::ostream& operator<<(std::ostream &os, quaternion_double const &q) ;

quaternion_double operator+(const quaternion_double &q);
void operator+=(const quaternion_double &q);
quaternion_double operator-(const quaternion_double &q);
void operator-=(const quaternion_double &q);
quaternion_double operator*(const quaternion_double &q);
void operator*=(const quaternion_double &q);
bool operator==(const quaternion_double &q);

quaternion_double operator+(const double &a);
void operator+=(const double &a);
quaternion_double operator-(const double &a);
void operator-=(const double &a);
quaternion_double operator*(const double &a);
void operator*=(const double &a);
quaternion_double operator/(const double &a);
void operator/=(const double &a);
bool operator==(const double &a);


quaternion_double getUnitquaternion();
quaternion_double getInverse();
quaternion_double operator/(const quaternion_double&q);
void operator/=(const quaternion_double &q);

quaternion_double operator+(const Math::complex_double &z);
void operator+=(const Math::complex_double &z);
quaternion_double operator-(const Math::complex_double &z);
void operator-=(const Math::complex_double &z);
quaternion_double operator*(const Math::complex_double &z);
void operator*=(const Math::complex_double &z);
quaternion_double operator/(const Math::complex_double &z);
void operator/=(const Math::complex_double &z);
bool operator==(const Math::complex_double &z);

quaternion_double operator+(const vec3d &v);
void operator+=(const vec3d &v);
quaternion_double operator-(const vec3d &v);
void operator-=(const vec3d &v);
quaternion_double operator*(const vec3d &v);
void operator*=(const vec3d &v);
quaternion_double operator/(const vec3d &v);
void operator/=(const vec3d &v);
bool operator==(const vec3d &v);

private:

};

class Vector
{
    public:
    Vector(int size);
    Vector(int size,double* data);
    Vector(const Vector& vec);
    Vector& operator=(const Vector& vec);

    Vector operator+(const Vector &v) const;
    void operator+=(const Vector &v);
    Vector operator-(const Vector &v) const;
    void operator-=(const Vector &v);
    double operator*(const Vector &v) const;
    Vector operator*(const double &a) const;
    void operator*=(const double &a);
    Vector operator/(const double &a) const;
    void operator/=(const double &a);
    bool operator==(const Vector &v) const;
    Vector operator*(Matrix &mat) const;

    ~Vector();
    std::string ToString() const;
    double getMagnitude() const;
    Vector unitVector() const;
    int getSize() const;
    double getElement(int index) const;
    void setElement(int index,double newElement);
    double& operator[](int index);
    bool isUnit() const;
    bool isNull() const;
    bool isValid() const;
    private:
    int size;
    double* vData;
};

Vector operator*(Matrix& mat,Vector& vec);

}



//Optional:Bordare
