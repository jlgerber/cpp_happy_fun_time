//
// Created by Jonathan Gerber on 10/31/16.
//
#pragma once


struct Vector {
    double x, y, z;
    Vector();
    Vector(double x_, double y_, double z_);
    Vector operator+(const Vector& rhs) const;
    Vector operator-(const Vector& rhs) const;

    Vector& operator+=(const Vector& rhs);
    Vector& operator-=(const Vector& rhs);

    Vector operator*(const double d) const;

    // dot product
    double operator*(const Vector& rhs) const;
    // cross product
    Vector cross(const Vector& rhs) const;

    bool operator==(const Vector& rhs) const;

    double length() const;

    void normalize();
};

