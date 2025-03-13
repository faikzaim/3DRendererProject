//
// Created by faikz on 10/02/2025.
//

#ifndef VECTOR_H
#define VECTOR_H
class Vector3 {
private:
    float x, y, z;
public:
    //Creates a vector with specified values
    Vector3(float x, float y, float z);
    //Destroys vector created
    ~Vector3();
    //Adds two vectors together
    Vector3 operator+(const Vector3 &other) const;
    //Subtracts two vectors together
    Vector3 operator-(const Vector3 &other) const;
    //This is the dot product of two vectors
    float operator*(const Vector3 &other) const;
};
#endif //VECTOR_H
