#include <iostream>

typedef float real;

using namespace std;

class Vector3
{
public:
    /*Holds the value along x-axis*/
    real x;
    
    /*Holds the value along y-axis*/
    real y;
    
    /*Holds the value along z-axis*/
    real z;

private:
    /*Padding*/
    real pad;

public:
    /*Default Constructor initialises to zero vector*/
    Vector3() : x(0),y(0),z(0){}
    
    /*Explicit Constructor*/
    Vector3(const real x,const real y,const real z) : x(x),y(y),z(z){}
    
    /*Flips all components of the vector*/
    void invert(){
        x=-x;
        y=-y;
        z=-z;
    }

    /*Gets the magnitude of this vector*/
    real magnitude() const{
        return real_sqrt(x*x+y*y+z*z);
    }

    /*Gets the squared magnitude of this vector*/
    real squareMagnitude() const{
        return x*x+y*y+z*z;
    }

    /*Multiplies this vector by the given scalar*/
    void operator*=(const real value)
    {
        x *= value;
        y *= value;
        z *= value;
    }

    /*Turns a non-zero vector into a vector of unit length*/
    void normalize(){
        real l = magnitude();

        if(l>0){
            (*this) *= ((real)1)/l;
        }
    }
    
    /*Returns a copy of this vector scaled by the given value*/
    Vector3 operator*(const real value) const
    {
        return Vector3(x*value,y*value,z*value);
    }

    /*Adds the given vector to this*/
    void operator+=(const Vector3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    /*Returns the value of the given vector added to this*/
    Vector3 operator+(const Vector3& v)
    {
        return Vector3(x+v.x, y+v.y, z+v.z);
    }
    
    /*Subtracts the given vector from this*/
    void operator-=(const Vector3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }

    /*Returns the value of the given vector added to this*/
    Vector3 operator-(const Vector3& v) const
    {
        return Vector3(x-v.x, y-v.y, z-v.z);
    }

    /*Adds the given vector scaled by the given amount to this*/
    void addScaledVector(const Vector3& v, real scale)
    {
        x += v.x * scale;
        y += v.y * scale;
        z += v.z * scale;
    }

    /*Calculates and returns the component-wise product of this with given vector*/
    Vector3 componentProduct(const Vector3& v) const
    {
        return Vector3(x*v.x, y*v.y, z*v.z);
    }

    /*Performs a component product and sets this vector to the result*/
    void componentProductUpdate(const Vector3& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
    }

    /*Calculates and returns the scalar product of this vector with the given vector*/
    real scalarProduct(const Vector3& v) const
    {
        return x*v.x + y*v.y + z*v.z;
    }

    /*Calculates and returns the scalar product of this vector with the given vector*/
    real operator*(const Vector3& v) const
    {
        return x*v.x + y*v.y + z*v.z;
    }

    /*Calculates and returns the vector product of this vector with the given vector*/
    Vector3 vectorProduct(const Vector3& v) const
    {
        return Vector3(y*v.z - z*v.y,
                       z*v.x - x*v.z,
                       x*v.y - y*v.x);
    }

    /*Calculates and returns the vector product of this vector with the given vector*/
    Vector3 operator%(const Vector3& v) const
    {
        return Vector3(y*v.z - z*v.y,
                       z*v.x - x*v.z,
                       x*v.y - y*v.x);
    }

    /*Updates this vector to be the vector product of the given vector and the current vector*/
    void operator%=(const Vector3& v)
    {
        *this = vectorProduct(v);
    }
};