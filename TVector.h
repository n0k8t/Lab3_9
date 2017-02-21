#ifndef LAB_3_TVECTOR_H
#define LAB_3_TVECTOR_H

#pragma once
#include <iostream>

class TVector
{
private:
    double * Data;
    size_t Len;
public:

    ~TVector();

    TVector();

    TVector(const TVector & rhs);

    TVector(const double * const data, const size_t len);

    TVector & operator=(const TVector & rhs);

    TVector & operator+=(const double * const data);

    double operator[](size_t index) const;
    double& operator[](size_t index);
};

TVector operator+(const double * const b, const TVector & a);

#endif //LAB_3_TVECTOR_H
