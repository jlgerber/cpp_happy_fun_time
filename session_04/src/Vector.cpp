//
// Created by Jonathan Gerber on 10/31/16.
//

#include "Vector.hpp"
#include <cmath>

Vector::Vector() :  x{0.0},
                    y{0.0},
                    z{1.0}
{}

Vector::Vector(double x_, double y_, double z_) :
    x{x_},
    y{y_},
    z{z_}
{}

Vector Vector::operator+(const Vector &rhs) const {
    return Vector(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector Vector::operator-(const Vector &rhs) const {
    return Vector(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector& Vector::operator+=(const Vector &rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

Vector Vector::operator*(const double d) const {
    return Vector(x*d, y*d, z*d);
}

// dot product
double Vector::operator*(const Vector &rhs) const {
    return x*rhs.x + y*rhs.y + z*rhs.z;
}

bool Vector::operator==(const Vector &rhs) const {
    return x == rhs.x && y == rhs.y && z == rhs.z;
}

Vector Vector::cross(const Vector &rhs) const {
    return Vector(y * rhs.z - z * rhs.y,
                  z * rhs.x - x * rhs.z,
                  x * rhs.y - y * rhs.x);
}

void Vector::normalize() {
    double len = sqrt(x*x + y*y + z*z);
    x /= len;
    y /= len;
    z /= len;
}

double Vector::length() const {
    return sqrt(x * x + y * y + z * z);
}
