//
// Created by faikz on 10/02/2025.
//
#include "Vector3.h"

Vector3::Vector3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}
Vector3::~Vector3() = default;
Vector3 Vector3::operator+(const Vector3 &other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}
Vector3 Vector3::operator-(const Vector3 &other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}
float Vector3::operator*(const Vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;
}


